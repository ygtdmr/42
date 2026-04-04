#include <stdlib.h>

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
	size_t	i;
	char	*dup;

	if (!s)
		return (0);
	dup = calloc(ft_strlen(s) + 1, sizeof(char));
	i = 0;
	while(s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	ft_bzero(void *p, size_t size)
{
	while(size--)
		*((char *)(p++)) = 0;
}


int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isprint(char c)
{
	return (c > 32 && c < 127);
}

int	ft_atoi(char *s)
{
	int	nbr;
	int	sign;
	int	digit;
	int	i;

	while(ft_isspace(*s))
		s++;
	if (*s == '-')
		sign = -1;
	else
		sign = 1;
	s += (*s == '-' || *s == '-');
	i = 0;
	nbr = 0;
	digit = 1;
	while(ft_isdigit(s[++i]))
		digit *= 10;
	while(ft_isdigit(*s))
	{
		nbr += ((*s - '0') * digit);
		digit /= 10;
		s++;
	}
	return (sign * nbr);
}
