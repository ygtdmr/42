*This project has been created as part of the 42 curriculum by ygtdmr.*

# cub3d

## Description

cub3d is a ray-casting 3D renderer inspired by Wolfenstein 3D. It parses a .cub configuration and map, loads four XPM wall textures, computes camera rays with a DDA traversal, draws floor and ceiling colours, and renders textured wall columns through MiniLibX. Keyboard handlers provide movement and left/right rotation, and the window close hook releases the allocated resources.

The branch keeps the project-local get_next_line and libft code, map examples, and texture assets used by the source. The Makefile also expects minilibx-linux, which is not included in the current tree.

## Instructions

The Makefile targets Linux MiniLibX, X11, libm, and readline in addition to a C compiler and GNU Make. After installing or placing MiniLibX at minilibx-linux, build with:

~~~sh
make
~~~

Run the renderer with a map file:

~~~sh
./cub3d maps/map_1.cub
~~~

The Makefile provides all, clean, fclean, re, and an empty bonus target. On this branch, the build is currently blocked by the missing minilibx-linux directory; the command above is the intended invocation once that dependency is supplied.

## Resources

- [MiniLibX guide](https://harm-smits.github.io/42docs/libs/minilibx)
- [DDA line drawing and ray casting reference](https://lodev.org/cgtutor/raycasting.html)
- [POSIX file operations](https://pubs.opengroup.org/onlinepubs/9699919799/)
- The 42 cub3d subject is the reference for the .cub format, map validation, ray casting, textures, and controls.

### AI Usage

AI was used during this repository task to inspect the parser, DDA/camera structures, rendering loop, assets, and Makefile, and to identify the missing MiniLibX dependency. The implementation was preserved and the README was checked against the source.

