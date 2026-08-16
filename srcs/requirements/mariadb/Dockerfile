FROM alpine:3.18

RUN apk update && apk add --no-cache mariadb mariadb-client

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

COPY conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh

ENTRYPOINT ["/usr/local/bin/init.sh"]
