/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:30:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/28 12:57:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_tokens(t_shell *sh)
{
	t_token	*next;

	next = sh->token_head;
	while (next)
	{
		printf("[%d:%s] ", next->type, next->value);
		next = next->next;
	}
	printf("\n");
}

void	print_envp(t_shell *sh)
{
	t_env	*next;

	next = sh->env_head;
	while (next)
	{
		printf("%s=%s\n", next->key, next->value);
		next = next->next;
	}
}
