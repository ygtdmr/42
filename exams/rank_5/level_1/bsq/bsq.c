#include <stdio.h>
#include <stdlib.h>

typedef struct s_bsq
{
	size_t	map_height;
	char	chars[4];
	char	**map;
} t_bsq;


static void	clear_map(t_bsq *bsq)
{
	size_t	i;

	i = 0;
	if (bsq->map)
	{
		while (bsq->map[i])
			free(bsq->map[i++]);
		free(bsq->map);
		bsq->map = 0;
	}
}

static int	str_len(char *s)
{
	size_t	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

static int	str_c_same(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[j])
		{
			if (i != j && s[j] == s[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	str_c_printable(char *s)
{
	while (*s)
	{
		if (!(*s > 32 && *s < 127))
			return (0);
		s++;
	}
	return (1);
}

static int	line_only(char *s, char *only)
{
	int		match;
	size_t	i;

	while (*s != '\n')
	{
		i = 0;
		match = 0;
		while (only[i])
		{
			if (*s == only[i])
				match = 1;
			i++;
		}
		if (!match)
			return (0);
		s++;
	}
	return (1);
}

static int	parse_header(t_bsq *bsq, FILE *file)
{
	if (!fscanf(file, "%zu%s\n", &bsq->map_height, bsq->chars))
		return (0);
	if (!(str_c_printable(bsq->chars) && !str_c_same(bsq->chars) && str_len(bsq->chars) == 3))
		return (0);
	return (1);
}

static int	parse_map(t_bsq *bsq, FILE *file)
{
	size_t	i;
	ssize_t	length;
	ssize_t	flength;
	size_t	tmp;
	char	only[3];

	i = 0;
	length = 0;
	flength = -1;
	only[0] = bsq->chars[0];
	only[1] = bsq->chars[1];
	only[2] = 0;
	while (1)
	{
		length = getline(bsq->map + i, &tmp, file);
		if (length == -1)
			break ;
		if (flength == -1)
			flength = length;
		if (flength != length)
			return (0);
		if (!line_only(*(bsq->map + i), only))
			return (0);
		i++;
	}
	free(bsq->map[i]);
	bsq->map[i] = 0;
	if (bsq->map_height != i)
		return (0);
	if (!flength)
		return (0);
	return (1);
}

static void process(t_bsq *bsq)
{
	size_t	i;

	i = 0;
	while (bsq->map[i])
	{
		fprintf(stdout, "%s", bsq->map[i]);
		i++;
	}
}

static int	run(t_bsq *bsq, FILE *file)
{
	if (!file)
		return (0);
	if (!parse_header(bsq, file))
		return (0);
	bsq->map = calloc(bsq->map_height + 1, sizeof(char *));
	if (!parse_map(bsq, file))
		return (0);
	process(bsq);
	return (1);
}

static void	ft_bzero(void *data, size_t size)
{
	while (size--)
		*((char *)data++) = 0;
}

int main(int argc, char **argv)
{
	int		err;
	t_bsq	bsq;
	FILE	*file;

	ft_bzero(&bsq, sizeof(bsq));
	argc--;
	argv++;
	if (argc >= 1)
	{
		while (argc--)
		{
			file = fopen(*argv++, "r");
			err = !run(&bsq, file);
			if (file)
				fclose(file);
			clear_map(&bsq);
			if (err)
				break;
		}
	}
	else
		err = !run(&bsq, stdin);
	if (err)
		fprintf(stderr, "map error\n");
	return (err);
}
