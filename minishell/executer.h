/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/30 12:18:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

void	executer(t_shell *sh);
void	do_exec(char *path, char **argv, char **env);
int		do_redir(t_redir *redir);
char	*path_resolve(char **env, char *file);
int		is_built_in(char *file);
void	bi_echo(int fd, char **argv);
void	bi_pwd(int fd, char **argv);
void	bi_cd(int fd, t_shell *sh, char **argv);
void	bi_env(int fd, char **env);
void	bi_export(t_shell *sh, char	**argv);
void	bi_unset(t_shell *sh, char **argv);

#endif
