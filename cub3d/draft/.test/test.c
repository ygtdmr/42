#include "test.h"

void	print_result(t_cub3d *cub3d)
{
	printf("img_no=|%p|\nimg_so=|%p|\nimg_we=|%p|\nimg_ea=|%p|\n\
f=(r=%d,g=%d,b=%d)\nc=(r=%d,g=%d,b=%d)\n cam(x=%0.2f, y=%0.2f, dir_x=%0.2f, dir_y=%0.2f, plane_x=%0.2f, plane_y=%0.2f)\n", \
	cub3d->map.img_no.mlx_img, cub3d->map.img_so.mlx_img, cub3d->map.img_we.mlx_img, cub3d->map.img_ea.mlx_img, \
	(cub3d->map.rgb_f >> 16) & 255, (cub3d->map.rgb_f >> 8) & 255, cub3d->map.rgb_f & 255, \
	(cub3d->map.rgb_c >> 16) & 255, (cub3d->map.rgb_c >> 8) & 255, cub3d->map.rgb_c & 255, \
	cub3d->cam.x, cub3d->cam.y,
	cub3d->cam.dir_x, cub3d->cam.dir_y, 0.0, 0.0);

	int i = 0;
	printf("map content:\n");
	while (cub3d->map.content && cub3d->map.content[i])
		printf("%s", cub3d->map.content[i++]);
}
