/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:09:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 15:05:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include "minishell_bonus.h"

int		is_operator(t_toktype type);
void	argv_push(char ***dest, char *src);
void	parser(t_shell *sh);
void	clear_cmd(t_cmd **head);
t_cmd	*new_cmd(t_cmd **head);

#endif
