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

static int	repeat_nbr(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (*tmp->nbr == *s->nbr)
				return (0);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (1);
}

static int	check_nbr(char *src)
{
	char	*tmp;
	char	*nbr;

	tmp = src;
	if (*src == '+' || *src == '-')
		src++;
	while (*src)
	{
		if (!(*src >= 48 && *src <= 57))
			return (0);
		src++;
	}
	nbr = ft_itoa(ft_atoi(tmp));
	if (!ft_strnstr(tmp, nbr, ft_strlen(tmp)))
	{
		free(nbr);
		return (0);
	}
	free(nbr);
	return (1);
}

static int	str_to_stack(char *str, t_stack **s)
{
	char	**splt;
	int		lsplt;
	int		status;

	splt = ft_split(str, ' ');
	lsplt = 0;
	while (splt[lsplt])
		lsplt++;
	status = args_to_stack(lsplt, splt, s);
	while (lsplt--)
		free(splt[lsplt]);
	free(splt);
	if (!status)
		stack_clear(s, free);
	return (status);
}

int	args_to_stack(int argc, char **argv, t_stack **s)
{
	t_stack	*ns;
	int		*nbr;

	*s = 0;
	while (argc--)
	{
		if (ft_strchr(*argv, ' '))
		{
			if (!str_to_stack(*argv++, &ns))
				return (0);
			stack_add_back(s, ns);
			continue ;
		}
		if (!check_nbr(*argv))
			return (0);
		nbr = (int *) malloc(sizeof(int));
		ns = stack_new(nbr);
		if (!nbr || !ns)
			return (0);
		*nbr = ft_atoi(*argv++);
		stack_add_back(s, ns);
	}
	if (!repeat_nbr(*s))
		return (0);
	return (1);
}
