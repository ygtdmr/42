FROM alpine:3.18

RUN apk update && apk add --no-cache redis

COPY conf/redis.conf /etc/redis.conf
COPY tools/init.sh /usr/local/bin/init.sh

RUN chmod +x /usr/local/bin/init.sh

EXPOSE 6379

ENTRYPOINT ["/usr/local/bin/init.sh"]
