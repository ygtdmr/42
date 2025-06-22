/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/22 19:16:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

void	executer(t_shell *sh);
char	*path_resolve(char *file);
int		path_validate(t_shell *sh, char *file);
void	exec_error(char	*msg, char *var);
int		is_built_in(char *file);
void	bi_echo(char **argv);
void	bi_pwd(char **argv);
void	bi_cd(char **argv);
void	bi_exit(t_shell *sh);
void	bi_env(char **env);
void	bi_export(t_shell *sh, char	**argv);
void	bi_unset(t_shell *sh, char **argv);

#endif
