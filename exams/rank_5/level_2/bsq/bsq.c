#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct	s_axis
{
	size_t	x;
	size_t	y;
	size_t	size;
}	t_axis;

typedef struct	s_bsq
{
	char	e;
	char	o;
	char	f;
	size_t	size;
	char	**map;
	int		**map_d;
}	t_bsq;

int min(int x, int y, int z)
{
    int m = x;
    if (y < m)
		m = y;
    if (z < m)
		m = z;
    return (m);
}

void	process(t_bsq	*bsq)
{
	size_t	x;
	size_t	y;
	t_axis	max;

	y = 0;
	max.size = 0;
	while(y < bsq->size)
	{
		x = 0;
		while(bsq->map[y][x])
		{
			if (bsq->map[y][x] == bsq->o)
				bsq->map_d[y][x] = 0;
			else if(!y || !x)
				bsq->map_d[y][x] = 1;
			else
				bsq->map_d[y][x] = min(bsq->map_d[y][x - 1], bsq->map_d[y - 1][x], bsq->map_d[y - 1][x - 1]) + 1;
			if (bsq->map_d[y][x] > max.size)
			{
				max.size = bsq->map_d[y][x];
				max.x = x;
				max.y = y;
			}
			x++;
		}
		y++;
	}
	y = 0;
	while(y < max.size)
	{
		x = 0;
		while(x < max.size)
		{
			bsq->map[max.y - y][max.x - x] = bsq->f;
			x++;
		}
		y++;
	}
	y = 0;
	while(y < bsq->size)
	{
		fputs(bsq->map[y], stdout);
		y++;
	}
}

int	parse_header(char *l, t_bsq *bsq)
{
	size_t	sdl;

	if (!l)
		return (0);
	sdl = 0;
	while(isdigit(l[sdl]))
		sdl++;
	if (!sdl)
		return (0);
	bsq->size = atoi(l);
	l += sdl;
	if (!(strlen(l) == 4 && l[3] == '\n'))
		return (0);
	if (!(isprint(l[0]) && isprint(l[1]) && isprint(l[2])))
		return (0);
	if (!(l[0] != l[1] && l[0] != l[2] && l[1] != l[2]))
		return (0);
	bsq->e = l[0];
	bsq->o = l[1];
	bsq->f = l[2];
	return (1);
}

int	verify_line(char *l, t_bsq *bsq)
{
	char			*nlp;
	static size_t	prev_length;
	size_t			length;

	length = strlen(l);
	nlp = (l + (length - 1));
	if (!prev_length)
		prev_length = length;
	if (!(l && prev_length == length))
		return (0);
	while(l != nlp)
	{
		if (!((*l == bsq->e) || (*l == bsq->o) || (*l == bsq->f)))
			return (0);
		l++;
	}
	return (1);
}

int	safe_free(void *p, int status)
{
	if (p)
		free(p);
	return (status);
}

void	free_map(void **map, size_t size)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while(i < size)
		free(map[i++]);
	free(map);
}

int	parse(FILE *fp, t_bsq *bsq)
{
	char	*line;
	size_t	n;
	size_t	size;

	if (!fp)
		return (0);
	n = 0;
	size = 0;
	line = 0;
	if (!((getline(&line, &n, fp) != -1) && parse_header(line, bsq)))
		return (safe_free(line, 0));
	bsq->map = calloc(bsq->size, sizeof(char *));
	bsq->map_d = calloc(bsq->size, sizeof(int *));
	while(getline(&line, &n, fp) != -1)
	{
		if (!(size <= bsq->size && verify_line(line, bsq)))
			return (safe_free(line, 0));
		bsq->map[size] = strdup(line);
		bsq->map_d[size] = calloc(strlen(line), sizeof(int));
		size++;
	}
	return (safe_free(line, size == (bsq->size)));
}

void	run(char *path, t_bsq *bsq)
{
	FILE	*fp;

	bzero(bsq, sizeof(t_bsq));
	if (path)
		fp = fopen(path, "r");
	else
		fp = stdin;
	if (parse(fp, bsq))
		process(bsq);
	else
		fprintf(stderr, "error\n");
	if (fp && (fp != stdin))
		fclose(fp);
	free_map((void **) bsq->map, bsq->size);
	free_map((void **) bsq->map_d, bsq->size);
}

int	main(int argc, char **argv)
{
	t_bsq	bsq;

	if (argc > 1)
	{
		while(*(++argv))
			run(*argv, &bsq);
	}
	else
		run(0, &bsq);
	return (0);
}
