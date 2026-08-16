FROM alpine:3.18

RUN apk update && apk add --no-cache nginx openssl

RUN mkdir -p /run/nginx /var/www/html /etc/nginx/ssl

COPY conf/nginx.conf /etc/nginx/http.d/default.conf
COPY tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh

ENTRYPOINT ["/usr/local/bin/init.sh"]
