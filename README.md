*This project has been created as part of the 42 curriculum by ygtdmr.*

# so_long

## Description

so_long is a small 2D map game built with MiniLibX. It parses a .ber map, validates its characters and rectangular wall borders, checks that the player can reach the exit and collectibles, loads XPM assets, and renders the map in a window. The mandatory program handles keyboard movement and the bonus sources add animation and an enemy.

The branch includes the project-local get_next_line and libft sources required by the Makefile, map files, and texture assets. It also contains the Makefile's expected minilibx-linux dependency, but that dependency is not present in the checked-in tree.

## Instructions

The project needs a Linux MiniLibX checkout in minilibx-linux, X11 development libraries, a C compiler, and GNU Make. Once that dependency is available, build with:

~~~sh
make
make bonus
~~~

Run the mandatory game with a .ber map:

~~~sh
./so_long maps/map.ber
~~~

The bonus executable is written under bonus/so_long and uses the bonus map and asset set. The Makefile provides all, bonus, clean, fclean, and re. On this branch, make cannot complete until minilibx-linux is supplied because the Makefile invokes make in that directory.

## Resources

- [MiniLibX guide](https://harm-smits.github.io/42docs/libs/minilibx)
- [XPM format overview](https://www.xfree86.org/current/xpm.html)
- [POSIX open](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)
- The 42 so_long subject is the reference for map rules, movement, collectibles, exit validation, and bonus behaviour.

### AI Usage

AI was used to inspect the map validators, rendering code, assets, and Makefile, identify the missing minilibx-linux dependency, and draft this README. The game implementation and assets remain the checked-in project files.

