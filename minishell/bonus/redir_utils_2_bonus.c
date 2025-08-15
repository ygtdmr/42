/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:01:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 13:55:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	redir_ambiguous_error(t_redir *redir)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(redir->file, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	redir->fd = -2;
}

int	check_wildcard_ambiguous(t_redir *redir)
{
	char	**expanded_files;
	int		i;
	t_token	temp_token;

	ft_bzero(&temp_token, sizeof(t_token));
	temp_token.value = redir->file;
	var_tok_willcard(0, &temp_token, redir->file);
	if (temp_token.len_wc == 0)
	{
		if (temp_token.i_wc)
			free(temp_token.i_wc);
		return (0);
	}
	expanded_files = 0;
	argv_push_with_willcard(&expanded_files, &temp_token);
	if (temp_token.i_wc)
		free(temp_token.i_wc);
	if (expanded_files)
	{
		i = 0;
		while (expanded_files[i])
			free(expanded_files[i++]);
		free(expanded_files);
	}
	return (sl_count(expanded_files) > 1);
}
