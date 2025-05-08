/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:30:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/08 21:06:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_tokens(char *line, t_shell *sh)
{
	t_token	*fhead;
	t_token	*head;

	fhead = lexer(line, sh);
	head = fhead;
	while (head)
	{
		printf("[%d:%s] ", head->type, head->value);
		head = head->next;
	}
	printf("\n");
	lstclear_tok(&fhead);
}
