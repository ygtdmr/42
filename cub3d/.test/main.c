#include "../libft/libft.h"
#include <stdio.h>

int	str_ts(char **dest, char *set)
{
	int		found;
	size_t	i_dest;
	size_t	i_set;

	i_dest = 0;
	while ((*dest)[i_dest])
	{
		i_set = 0;
		found = 0;
		while (set[i_set])
		{	
			if (set[i_set] == (*dest)[i_dest])
			{
				found = 1;
				break ;
			}
			i_set++;
		}
		if (!found)
			break ;
		i_dest++;
	}
	*dest += i_dest;
	return (i_dest > 0);
}

void	*exit_err(char *msg1, char *msg2)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg1, 2);
	if (msg2)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg2, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(1);
	return (0);
}

static void	get_rgb(int *rgb, char *line)
{
	int	step;
	int	value;

	step = 2;
	while (1)
	{
		str_ts(&line, " \n");
		if (!*line)
			return ((void) exit_err("invalid config", "missing rgb value"));
		if (!ft_isdigit(*line))
			return ((void) exit_err("invalid config: invalid rgb", line));
		value = ft_atoi(line);
		if (value > 255)
			return ((void) exit_err("invalid config: (r,g,b) max 255", line));
		*rgb |= value << (8 * step);
		str_ts(&line, "0123456789");
		str_ts(&line, " \n");
		step--;			
		if (*line && (step == -1 || !str_ts(&line, ",")))
			return ((void) exit_err("invalid config: invalid rgb", line));
		if (step == -1)
			break ;
	}
}

int main(int argc, char **argv)
{
	int	rgb;
	rgb = 0;
	get_rgb(&rgb, argv[1]);
	printf("r=%d, g=%d, b=%d\n", (rgb >> 16) & 255, (rgb >> 8) & 255, rgb & 255);
}