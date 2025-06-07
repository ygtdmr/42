/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/07 13:35:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

void	executer(t_shell *sh);
char	*path_resolve(char *file);

#endif
