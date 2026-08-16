FROM alpine:3.18

RUN apk update && apk add --no-cache \
    php81 \
    php81-session \
    php81-mysqli \
    wget

WORKDIR /var/www

RUN wget -O index.php https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php

EXPOSE 8080

CMD ["php81", "-S", "[::]:8080", "-t", "/var/www"]
