/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:09:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 23:56:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	argv_push(char ***dest, char *src);
void	redir_push(t_redir **head, t_token token);
void	parser(t_shell *sh);
void	clear_cmd(t_cmd **head);
t_cmd	*new_cmd(t_cmd **head);
