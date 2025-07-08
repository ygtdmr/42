/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:09:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/08 14:04:06 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int		is_redir(int type);
void	argv_push(char ***dest, char *src);
void	parser(t_shell *sh);
void	clear_cmd(t_cmd **head);
t_cmd	*new_cmd(t_cmd **head);

#endif
