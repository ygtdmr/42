#!/bin/bash

for i in {0..16}
do
	./client $1 "Test string from: $i" &
	sleep 0.5
done

wait

echo "test done."
