#!/bin/bash
for i in $(ls maps/bad)
do
	echo -e -n "\033[1;90m$1/$i\033[0m: "
	valgrind --leak-check=full --show-leak-kinds=all ./cub3d "maps/bad/$i"
done
