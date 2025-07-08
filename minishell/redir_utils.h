/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:03:46 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/08 14:03:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_UTILS_H
# define REDIR_UTILS_H

# include "minishell.h"

int		is_redir(int type);
void	redir_push(t_cmd *cmd, t_redir **head, t_token **token);

#endif
