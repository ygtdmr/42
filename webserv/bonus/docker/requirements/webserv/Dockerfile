FROM debian:trixie-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    php-cli \
    php-mysqli \
    php-mbstring \
    php-iconv \
    php-curl \
    php-cgi \
    mariadb-client \
    wget \
    curl \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /.wp-cli
RUN chown -R 1000:1000 /.wp-cli

copy conf/wordpress.conf /etc/webserv/default.conf
COPY bin/webserv /usr/local/bin/webserv
COPY tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh
RUN chmod +x /usr/local/bin/webserv

RUN mkdir -p /var/www/html
RUN chown -R 1000:1000 /var/www/html

WORKDIR /var/www/html

USER 1000

ENTRYPOINT ["/usr/local/bin/init.sh"]
