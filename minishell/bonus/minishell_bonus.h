/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:42:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 13:09:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include <errno.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include "../libft/libft.h"

extern int	g_running;

typedef enum e_toktype
{
	T_WORD,
	T_PIPE,
	T_OPERATOR_OR,
	T_OPERATOR_AND,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APND,
	T_HEREDOC,
}	t_toktype;

typedef struct s_token
{
	char			*value;
	t_toktype		type;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	t_toktype		type;
	char			*file;
	int				fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	int				pid;
	int				last_status;
	int				redir_err;
	int				and_op;
	int				or_op;
	t_redir			*redir_head;
	char			**argv;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_token	*token_head;
	t_cmd	*cmd_head;
	char	**env;
	int		last_status;
	int		exit;
}	t_shell;

#endif
