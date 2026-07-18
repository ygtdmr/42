#!/bin/sh

DB_PWD=$(cat /run/secrets/db_password)
WP_ADMIN_PWD=$(cat /run/secrets/credentials)

if [ ! -f "/var/www/html/wp-config.php" ]; then
    echo 'WordPress setup running'

    php -d memory_limit=512M /usr/local/bin/wp core download

    wp config create --dbname=${DB_NAME} --dbuser=${DB_USER} --dbpass=${DB_PWD} --dbhost=mariadb

    wp core install --url=${DOMAIN_NAME} --title="Webserv Bonus" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PWD} \
        --admin_email=${WP_ADMIN_EMAIL} \

    wp user create ${WP_USER} ${WP_USER_EMAIL} --role=author --user_pass=${WP_ADMIN_PWD}

    echo 'WordPress setup done'
fi

exec /usr/local/bin/webserv /etc/webserv/default.conf
