#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_life
{
	int		width;
	int		height;
	int		it;
	int		**map;
	int		**map_tmp;
	char	*act;
}	t_life;

void	ft_bzero(void *p, size_t size)
{
	if (!(p && size))
		return ;
	while(size--)
		*((char *)p++) = 0;
}

void	clear_life(t_life *life)
{
	while(life->height--)
	{
		free(life->map[life->height]);
		free(life->map_tmp[life->height]);
	}
	free(life->map);
	free(life->map_tmp);
	free(life->act);
}

int	calculate_live(int **map, size_t x, size_t y, size_t w, size_t h)
{
	int	live;

	live = 0;
	live += (y > 0 && x > 0) && (map[y - 1][x - 1] == 1);
	live += (y > 0) && (map[y - 1][x] == 1);
	live += (y > 0 && (x + 1) != w) && (map[y - 1][x  + 1] == 1);

	live += ((y + 1) != h && x > 0) && (map[y + 1][x - 1] == 1);
	live += ((y + 1) != h) && (map[y + 1][x] == 1);
	live += ((y + 1) != h && (x + 1) != w) && (map[y + 1][x + 1] == 1);

	live += (x > 0) && (map[y][x - 1] == 1);
	live += ((x + 1) != w) && (map[y][x + 1] == 1);
	return (live);
}

void	map_cpy(int **dest, int **src, size_t w, size_t h)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(y < h)
	{
		x = 0;
		while (x < w)
		{
			dest[y][x] = src[y][x];
			x++;
		}
		y++;
	}
}

void	map_draw(t_life *life)
{
	size_t	x;
	size_t	y;
	size_t	i;
	int		pen;

	x = 0;
	y = 0;
	i = 0;
	pen = 0;
	while(life->act[i])
	{
		if (life->act[i] == 'w' && y > 0)
			y--;
		else if (life->act[i] == 'a' && x > 0)
			x--;
		else if (life->act[i] == 's' && y != life->height)
			y++;
		else if (life->act[i] == 'd' && x != life->width)
			x++;
		if (life->act[i] == 'x')
			pen = !pen;
		if (pen)
			life->map[y][x] = 1;
		i++;
	}
}

void	map_print(t_life *life)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			if (life->map[y][x] == 1)
				putchar('O');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}

void	run_it(t_life *life)
{
	size_t	x;
	size_t	y;
	int		live;

	y = 0;
	while(y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			live = calculate_live(life->map, x, y, life->width, life->height);
			if (life->map[y][x] == 1)
				life->map_tmp[y][x] = (live == 2 || live == 3);
			else
				life->map_tmp[y][x] = (live == 3);
			x++;
		}
		y++;
	}
}

void	run(t_life *life)
{
	size_t	i;

	life->map = calloc(life->height, sizeof(int *));
	life->map_tmp = calloc(life->height, sizeof(int *));
	i = 0;
	while(i < life->height)
	{
		life->map[i] = calloc(life->width, sizeof(int));
		life->map_tmp[i] = calloc(life->width, sizeof(int));
		i++;
	}
	map_draw(life);
	map_cpy(life->map_tmp, life->map, life->width, life->height);
	while(life->it--)
	{
		run_it(life);
		map_cpy(life->map, life->map_tmp, life->width, life->height);
	}
	map_print(life);
}

int	main(int argc, char **argv)
{
	t_life	life;
	size_t	act_l;

	if (argc != 4)
		return(1);
	ft_bzero(&life, sizeof(t_life));
	act_l = 0;
	life.width = atoi(argv[1]);
	life.height = atoi(argv[2]);
	life.it = atoi(argv[3]);
	if (life.width <= 0 || life.height <= 0 || life.it < 0)
    	return (1);
	life.act = calloc(2, sizeof(char));
	while (read(0, life.act + act_l, 1) > 0)
	{
		act_l++;
		life.act = realloc(life.act, act_l + 1);
		life.act[act_l] = 0;
	}
	run(&life);
	clear_life(&life);
	return (0);
}
