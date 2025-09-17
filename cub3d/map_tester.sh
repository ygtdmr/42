for i in $(ls $1)
do
	echo -e -n "\033[1;90m$1/$i\033[0m: "
	./cub3d "$1/$i"
done
