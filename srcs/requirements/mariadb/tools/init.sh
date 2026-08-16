#!/bin/sh

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

DB_ROOT_PWD=$(cat /run/secrets/db_root_password)
DB_PWD=$(cat /run/secrets/db_password)

cat << EOF > /tmp/init.sql
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PWD}';
CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
CREATE USER IF NOT EXISTS \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PWD}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO \`${DB_USER}\`@'%';
FLUSH PRIVILEGES;
EOF

mysqld --user=mysql --bootstrap < /tmp/init.sql

rm -f /tmp/init.sql

exec mysqld --user=mysql --console
