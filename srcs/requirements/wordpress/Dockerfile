FROM alpine:3.18

RUN apk update && apk add --no-cache \
    php81 php81-fpm php81-mysqli php81-phar \
    php81-mbstring php81-iconv php81-curl \
    mariadb-client wget curl

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php81/php-fpm.d/www.conf
COPY tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh

WORKDIR /var/www/html

ENTRYPOINT ["/usr/local/bin/init.sh"]
