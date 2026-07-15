#!/bin/bash

HOST="127.0.0.1"
PORT="8080"
URI="/directory/youpi.bla"

WORKERS=20
REQUESTS=5
SIZE=100000000

PAYLOAD="/tmp/webserv_payload.bin"

echo "=== Webserv Stress Test ==="
echo "Target : http://$HOST:$PORT$URI"
echo "Workers: $WORKERS"
echo "Requests per worker: $REQUESTS"
echo

echo "[1/3] Checking server..."

if ! curl -s --connect-timeout 2 "http://$HOST:$PORT/" > /dev/null; then
    echo "Server is not reachable."
    echo "Start your webserv first."
    exit 1
fi

echo "Server is online."

echo "[2/3] Preparing payload..."

if [ ! -f "$PAYLOAD" ]; then
    head -c "$SIZE" /dev/zero > "$PAYLOAD"
fi

echo "Payload size: $(stat -c%s "$PAYLOAD") bytes"
echo

echo "[3/3] Sending requests..."

worker() {
    id=$1

    for ((i=1;i<=REQUESTS;i++)); do

        RESULT=$(curl \
            --silent \
            --output /dev/null \
            --write-out "%{http_code} %{time_total}" \
            --data-binary @"$PAYLOAD" \
            -X POST \
            "http://$HOST:$PORT$URI")

        CODE=$(echo "$RESULT" | awk '{print $1}')
        TIME=$(echo "$RESULT" | awk '{print $2}')

        printf "Worker %02d | Request %d | HTTP %s | %ss\n" \
            "$id" "$i" "$CODE" "$TIME"

    done
}

for ((w=1;w<=WORKERS;w++)); do
    worker "$w" &
done

wait

echo
echo "Stress test finished."