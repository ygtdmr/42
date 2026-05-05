FROM alpine:3.18

RUN apk update && apk add --no-cache php php-session php-dom php-xml php-simplexml php-json php-mbstring wget tar

WORKDIR /var/www/html

RUN wget https://github.com/phpsysinfo/phpsysinfo/archive/refs/tags/v3.4.3.tar.gz -O phpsysinfo.tar.gz && \
    tar -xzf phpsysinfo.tar.gz --strip-components=1 && \
    rm phpsysinfo.tar.gz

RUN cp phpsysinfo.ini.new phpsysinfo.ini

EXPOSE 8083

CMD ["php", "-S", "0.0.0.0:8082"]
