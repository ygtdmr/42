/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:16:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/28 17:55:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parse.h"

void	lexer(char **line, t_shell *sh)
{
	while (*line)
	{
		if (mch_str(line, " ") || mch_str(line, "\t") || mch_str(line, "\n"))
			continue ;
		if (mch_str(line, "|"))
			new_tok(&sh->token_head, ft_strdup("|"), T_PIPE);
		else if (mch_str(line, ";"))
			new_tok(&sh->token_head, ft_strdup(";"), T_CMD_SEP);
		else if (mch_str(line, ">>"))
			new_tok(&sh->token_head, ft_strdup(">>"), T_REDIR_APND);
		else if (mch_str(line, "<<"))
			new_tok(&sh->token_head, ft_strdup("<<"), T_HEREDOC);
		else if (mch_str(line, "<"))
			new_tok(&sh->token_head, ft_strdup("<"), T_REDIR_IN);
		else if (mch_str(line, ">"))
			new_tok(&sh->token_head, ft_strdup(">"), T_REDIR_OUT);
		else
			new_tok(&sh->token_head, parse(grab_word(sh, line), sh), T_WORD);
	}
}
