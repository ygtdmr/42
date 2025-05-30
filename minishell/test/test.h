/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 23:52:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "../minishell.h"
# include "../lexer.h"
# include "../env_list.h"

void	print_envp(t_shell *sh);
void	print_tokens(t_shell *sh);
void	print_cmd(t_shell *sh);

#endif
