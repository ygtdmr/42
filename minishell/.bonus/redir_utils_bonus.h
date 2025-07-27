/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:03:46 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/15 06:42:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_UTILS_BONUS_H
# define REDIR_UTILS_BONUS_H

# include "minishell_bonus.h"

int		is_redir(int type);
void	redir_push(t_redir **head, t_token **token);
void	check_redir_fd(t_cmd *cmd);

#endif
