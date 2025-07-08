/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/08 15:49:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"

void	bi_echo(int fd, char **argv);
void	bi_pwd(int fd);
void	bi_cd(int fd, t_shell *sh, t_cmd *cmd);
void	bi_cd_after(t_shell *sh, t_cmd *cmd, char *oldpwd, int status);
void	bi_env(int fd, char **env);
void	bi_export(int fd, t_shell *sh, t_cmd *cmd, int has_pipe);
void	bi_unset(t_shell *sh, t_cmd *cmd, int has_pipe);
void	bi_exit(t_shell *sh, t_cmd *cmd, int has_pipe);
int		arg_is_option(char *arg, char option);

#endif
