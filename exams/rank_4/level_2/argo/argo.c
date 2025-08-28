#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

static size_t	str_len(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	argo(json *dst, FILE *stream);

static int	put_err(char c)
{
	if (c)
		printf("unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
	return (0);
}

static int	get_map(json *j, FILE *stream)
{
	json	value;
	char	c;

	c = getc(stream);
	if (!c)
		put_err(0);
	if (c != '}')
	{
		j->map.size++;
		if (getc(stream) != '\"')
			return (put_err(c));
		if (!get_str(&j->map.data->key, stream))
			return (put_err(0));
		if (getc(stream) != ':')
			return (put_err(c));
		if (!argo(&value, stream))
			return (0);
		return (get_map(&j->map.data->value, stream));
	}
	return (1);
}

static int	get_str(char **dst, FILE *stream)
{
	size_t	len;
	char	c;

	c = getc(stream);
	if (!c)
	{
		free(*dst);
		return (put_err(0));
	}
	if (c != '\"')
	{
		len = str_len(*dst);
		*dst = realloc(*dst, sizeof(char) * (len + 1));
		(*dst)[len] = c;
		return (get_str(*dst, stream));
	}
	return (1);
}
static int	get_int(FILE *stream)
{
	int	i;

	fscanf(stream, "%d", &i);
	return (i);
}

int	argo(json *dst, FILE *stream)
{
	char	*str;
	char	c;

	c = getc(stream);
	if (c == '\"')
	{
		if (!get_str(str, stream))
			return (0);
		dst->type = STRING;
		dst->string = str;
	}
	else if (c == '{')
	{
		dst->type = MAP;
		if (!get_map(dst, stream))
			return (0);
	}
	else if (isdigit(c))
	{
		dst->type = INTEGER;
		dst->integer = get_int(stream);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*filename = argv[1];
	FILE	*stream = fopen(filename, "r");
	json	file;

	if (argc != 2)
		return (1);
	if (!argo(&file, stream))
	{
		free_json(file);
		return (1);
	}
	serialize(file);
	printf("\n");
}
