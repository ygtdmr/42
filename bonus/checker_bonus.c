/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:58 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/01 00:48:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	stack_error(t_stack **sa, t_stack **sb)
{
	write(2, "Error\n", 6);
	stack_clear(sa);
	stack_clear(sb);
	return (1);
}

static void	check(t_stack **sa, t_stack **sb)
{
	char	**acl;
	char	*acs;
	int		i;

	acl = 0;
	acs = get_actions();
	if (acs && (*acs == '\n' || (ft_strnstr(acs, "\n\n", ft_strlen(acs)) != 0)))
	{
		free(acs);
		exit(stack_error(sa, sb));
	}
	if (acs)
	{
		acl = ft_split(acs, '\n');
		free(acs);
	}
	if (acl && !valid_actions(acl))
	{
		clear_actions(acl);
		exit(stack_error(sa, sb));
	}
	i = 0;
	while (acl && acl[i])
		stack_action(acl[i++], sa, sb);
	clear_actions(acl);
}

int	main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;

	sb = 0;
	if (argc < 2)
		return (0);
	if (!args_to_stack(--argc, ++argv, &sa))
		return (stack_error(&sa, &sb));
	if (stack_size(sa))
	{
		check(&sa, &sb);
		if (stack_sorted(sa) && !stack_size(sb))
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
	stack_clear(&sa);
	stack_clear(&sb);
	return (0);
}
