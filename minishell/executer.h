/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/19 18:00:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

void	executer(t_shell *sh);
char	*path_resolve(char *file);
int		path_exists(t_shell *sh, char *file);
int		is_built_in(char *file);
int		str_match(char *dest, char *src);
void	bi_echo(char **argv);
void	bi_pwd(char **argv);
void	bi_cd(char **argv);
void	bi_exit(t_shell *sh);

#endif
