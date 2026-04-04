#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_bsq
{
	char	**map;
	char	empty;
	char	obstacle;
	char	full;
	size_t	len;
}	t_bsq;

void	put_err(void)
{
	fprintf(stderr, "map error\n");
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while(s && s[l])
		l++;
	return (l);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	i_dup;
	size_t	len;

	i_dup = 0;
	len = ft_strlen(s);
	dup = calloc((len + 1), sizeof(char));
	while(i_dup < len)
	{
		dup[i_dup] = s[i_dup];
		i_dup++;
	}
	return (dup);
}

int	verify_line(t_bsq *bsq, char *line)
{
	char	e;
	char	o;
	char	f;
	char	*nl;

	e = bsq->empty;
	o = bsq->obstacle;
	f = bsq->full;
	nl = line + ft_strlen(line) - 1;
	while (line && *line)
	{
		if ((line != nl) && (*line != e) && (*line != o) && (*line != f))
			return (0);
		line++;
	}
	return (1);
}

int	parse_config(t_bsq *bsq, char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != 5)
		return (0);
	while(line[i])
	{
		if (i == 0)
		{
			if(line[i] >= '0' && line[i] <= '9')
				bsq->len = line[i] - '0';
			else
				return (0);
		}
		else if(i == 1)
			bsq->empty = line[i];
		else if(i == 2)
			bsq->obstacle = line[i];
		else if(i == 3)
			bsq->full = line[i];
		i++;
	}
	return (1);
}

int	parse(t_bsq *bsq, FILE *fp)
{
	char	*line;
	size_t	buf_len;
	ssize_t	tmp_len;
	size_t	i_map;
	size_t	l_map;

	buf_len = 0;
	line = 0;
	if (!fp)
		return (0);
	tmp_len = getline(&line, &buf_len, fp);
	if (!((tmp_len != -1) && parse_config(bsq, line)))
	{
		free(line);
		return (0);
	}
	bsq->map = calloc((bsq->len + 1), sizeof(char *));
	tmp_len = -1;
	i_map = 0;
	l_map = 0;
	while(getline(&line, &buf_len, fp) != -1)
	{
		if (tmp_len == -1)
			tmp_len = ft_strlen(line);
		if (tmp_len != ft_strlen(line))
			break;
		if (verify_line(bsq, line))
			bsq->map[i_map++] = ft_strdup(line);
		else
			break;
		l_map++;
	}
	free(line);
	return ( bsq->len == l_map );
}

void	clean(t_bsq *bsq)
{
	size_t	i;

	if (!bsq->map)
		return; 
	i = 0;
	while(bsq->map[i])
		free(bsq->map[i++]);
	free(bsq->map);
	bsq->map = 0;
}

void	run(t_bsq *bsq)
{
	size_t	i;

	i = 0;
	fprintf(stdout, "config: l=%ld e=|%c| o=|%c| f=|%c|\n", bsq->len, bsq->empty, bsq->obstacle, bsq->full);
	while (bsq->map[i])
		fprintf(stdout, "%s", bsq->map[i++]);
}

int	main(int argc, char **argv)
{
	FILE	*fp;
	t_bsq	bsq;
	char	*line;

	bsq.map = 0;
	if (argc < 2)
	{
		if (parse(&bsq, stdin))
			run(&bsq);
		else
			put_err();
		clean(&bsq);
	}
	else
	{
		while (*(++argv))
		{
			fp = fopen(*argv, "r");
			if (parse(&bsq, fp))
				run(&bsq);
			else
				put_err();
			clean(&bsq);
			if (fp)
				fclose(fp);
		}
	}
	return (0);
}
