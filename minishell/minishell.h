/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:42:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 14:43:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft/libft.h"

extern int	g_running;

typedef enum e_toktype
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APND,
	T_HEREDOC
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

int		str_match(char *dest, char *src);
char	*str_lrealloc(char *dest, char *src, size_t length, int src_free);
void	str_lclean(char **dest, size_t length);
int		str_mc(char **dest, char *needle);
void	str_swap(char **x, char **y);

int		is_redir(int type);
void	redir_push(t_cmd *cmd, t_redir **head, t_token **token);

void	argv_push(char ***dest, char *src);
void	parser(t_shell *sh);
void	clear_cmd(t_cmd **head);
t_cmd	*new_cmd(t_cmd **head);

void	new_tok(t_token	**head, char *value, t_toktype type);
void	clear_tok(t_token **head);
void	add_tok(t_token **head, t_token *new);
int		last_tok_type_match(t_token *head, t_toktype type);
void	lexer(t_shell *sh, char **line);

size_t	char_len(char c, char *str);
int		is_rawchar(char c);
int		is_varchar(char c, size_t index);
int		compile_status(int status);
char	*expand(t_shell *sh, char *raw);

void	executer(t_shell *sh);
void	do_exec(char *path, char **argv, char **env);
char	*path_resolve(char **env, char *file);
int		is_bi(char *file);
int		apply_redirs(t_cmd *cmd, int *in, int *out);

void	env_append(char ***env, char *key, char *val);
char	*env_get(char **env, char *key);
char	*env_key(char *src);
int		env_key_exists(char **env, char *key);
int		env_key_validate(char *src, char *err_type);
void	clear_env(char **env);
char	**env_dup(char **env, int clear);
char	*env_str(char *key, char *val);

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
