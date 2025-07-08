/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/08 15:15:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

void	executer(t_shell *sh);
void	do_exec(char *path, char **argv, char **env);
char	*path_resolve(char **env, char *file);
int		is_bi(char *file);
int		apply_redirs(t_cmd *cmd, int *in, int *out);

#endif
