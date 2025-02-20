/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:42:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/03 21:12:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	repeat_nbr(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (*tmp->nbr == *s->nbr)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			tmp = tmp->next;
		}
		s = s->next;
	}
}

static void	check_nbr(char *src)
{
	char	*tmp;

	tmp = src;
	while (*src)
	{
		if (!(*src >= 48 && *src <= 57) && (*src != '+' && *src != '-'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		src++;
	}
	if (!ft_strnstr(tmp, ft_itoa(ft_atoi(tmp)), ft_strlen(tmp)))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static t_stack	*str_to_stack(char *str)
{
	t_stack	*stack;
	char	**splt;
	int		lsplt;

	splt = ft_split(str, ' ');
	lsplt = 0;
	while (splt[lsplt])
		lsplt++;
	stack = args_to_stack(lsplt, splt);
	free(splt);
	return (stack);
}

t_stack	*args_to_stack(int argc, char **argv)
{
	t_stack	*s;
	int		*nbr;

	s = 0;
	while (argc--)
	{
		if (ft_strchr(*argv, ' '))
		{
			stack_add_back(&s, str_to_stack(*argv++));
			continue ;
		}
		check_nbr(*argv);
		nbr = (int *) malloc(sizeof(int *));
		if (!nbr)
		{
			stack_clear(&s, free);
			return (0);
		}
		*nbr = ft_atoi(*argv++);
		stack_add_back(&s, stack_new(nbr));
	}
	repeat_nbr(s);
	return (s);
}
