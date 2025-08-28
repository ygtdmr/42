#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum
{
	ERR_EO = 1,
	ERR_IC = 2
} t_error;

typedef struct s_vbc
{
	const char	*s;
	int			i;
	t_error		err;
	char		errc;
}	t_vbc;

static void skip_spaces(t_vbc *vbc, int *r_i)
{
	const char	*s;
	int		i;

	s = vbc->s;
	i = vbc->i;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (r_i)
		*r_i = i;
	else
		vbc->i = i;
}

static char	peek(t_vbc *vbc)
{
	skip_spaces(vbc, 0);
	return (vbc->s[vbc->i]);
}

static void	next(t_vbc *vbc)
{
	skip_spaces(vbc, 0);
	if (vbc->s[vbc->i])
		vbc->i++;
}

static int	next_is(t_vbc *vbc, char c)
{
	int	r_i;

	skip_spaces(vbc, &r_i);
	if (vbc->s[r_i] == c)
	{
		vbc->i = r_i;
		return (1);
	}
	return (0);
}

static int	expr(t_vbc *vbc);

static int	factor(t_vbc *vbc)
{
	int		val;
	char	c;

	c = peek(vbc);
	if (c == '(')
	{
		next(vbc);
		val = expr(vbc);
		if (peek(vbc) == ')')
		{
			next(vbc);
			return (val);	
		}
		vbc->errc = 0;
		vbc->err = ERR_EO;
		return (0);
	}
	else if(isdigit(c))
	{
		next(vbc);
		return (c - '0');
	}
	else if(!peek(vbc))		
		vbc->err = ERR_EO;
	else
		vbc->err = ERR_IC;
	vbc->errc = peek(vbc);
	return (0);
}

static int	term(t_vbc *vbc)
{
	int	val;

	val = factor(vbc);
	while (next_is(vbc, '*'))
	{
		next(vbc);
		val *= factor(vbc);
	}
	return (val);
}

static int	expr(t_vbc *vbc)
{
	int	val;

	val = term(vbc);
	while (next_is(vbc, '+'))
	{
		next(vbc);
		val += term(vbc);
	}
	return (val);
}

static void	put_error(t_vbc *vbc)
{
	if (vbc->errc)
		printf("Unexpected token '%c'\n", vbc->errc);
	else
		printf("Unexpected end of input\n");
}

int main(int argc, char **argv)
{
	int			result;
	t_vbc	vbc;

    if (argc != 2)
        return (1);
	vbc.err = 0;
	vbc.errc = 0;
	vbc.i = 0;
	vbc.s = argv[1];
	result = expr(&vbc);
	if (peek(&vbc))
	{
		vbc.errc = peek(&vbc);
		vbc.err = ERR_IC;
	}
	if (vbc.err)
		put_error(&vbc);
	else
		printf("%d\n", result);
}
