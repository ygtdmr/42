FROM alpine:3.18

RUN apk update && apk add --no-cache lighttpd

COPY conf/lighttpd.conf /etc/lighttpd/lighttpd.conf
COPY html/ /var/www/html/

EXPOSE 8081

CMD ["lighttpd", "-D", "-f", "/etc/lighttpd/lighttpd.conf"]
