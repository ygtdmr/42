/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:58 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/24 21:26:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	stack_error(t_stack **sa, t_stack **sb)
{
	write(2, "Error\n", 6);
	stack_clear(sa, free);
	stack_clear(sb, free);
	return (1);
}

static int	check(t_stack **sa, t_stack **sb)
{
	char	**acl;
	int		i;

	acl = get_actions();
	if (!acl || !*acl)
		exit(stack_error(sa, sb));
	i = 0;
	while (acl[i])
		stack_action(acl[i++], sa, sb);
	i = 0;
	while (acl[i])
		free(acl[i++]);
	free(acl);
	return (stack_sorted(*sa));
}

int	main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;

	sb = 0;
	if (argc == 1)
		return (0);
	if (!args_to_stack(argc - 1, argv + 1, &sa))
		return (stack_error(&sa, &sb));
	if (check(&sa, &sb))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	stack_clear(&sa, free);
	stack_clear(&sb, free);
	return (0);
}
