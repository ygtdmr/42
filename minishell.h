/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:42:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 15:02:34 by yidemir          ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"

typedef enum e_toktype
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_ERR,
	T_REDIR_APND,
	T_HEREDOC
}	t_toktype;

typedef struct s_token
{
	int				quote;
	char			*value;
	t_toktype		type;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	t_toktype		type;
	char			*file;
	int				quote;
	int				fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	pid_t			pid;
	int				last_status;
	int				redir_err;
	t_redir			*redir_head;
	char			**argv;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_shell
{
	t_token	*token_head;
	t_cmd	*cmd_head;
	char	**env;
	char	*prompt;
	int		last_status;
	int		interactive;
	int		exit;
}	t_shell;

int		str_match(char *dest, char *src);
char	*str_lrealloc(char *dest, char *src, size_t length, int src_free);
char	*str_realloc(char *dest, char *src, int src_free);
void	str_lclean(char **dest, size_t length);
int		str_mc(char **dest, char *needle);
void	str_swap(char **x, char **y);
int		is_varchar(char *s, size_t index);

int		get_heredoc_fd(t_shell *sh, t_cmd *cmd, char *eof, int eof_quote);

void	change_fd(int *fd, int new);
void	redir_fetch_fds(t_shell *sh);
void	redir_push(t_redir **head, t_token **token);

void	argv_push(char ***dest, char *src);
void	parser(t_shell *sh);
void	clear_cmd(t_cmd **head);
t_cmd	*new_cmd(t_cmd **head);
t_cmd	*cmd_by_pid(t_cmd *head, pid_t pid);
t_cmd	*last_cmd(t_cmd *head);

void	new_tok(t_token	**head, char *value, t_toktype type);
void	clear_tok(t_token **head);
void	add_tok(t_token **head, t_token *new);
t_token	*lst_tok(t_token *head);
int		lst_tok_is(t_token *head, t_toktype type);
void	lexer(t_shell *sh, char **line);

void	tok_quote(t_token *token);
int		compile_status(int status);
void	var_append(t_shell *sh, char **raw, char **out, int dq);
void	var_append_exp(t_shell *sh, char **raw, char **out);
void	escape_append(char **raw, char **out, int dq);
char	*expand(t_shell *sh, char *raw);

void	executer(t_shell *sh);
void	do_exec(char *path, char **argv, char **env, int noenv);
char	*path_resolve(char **env, char *file);
int		is_bi(char *file);
int		apply_redirs(t_cmd *cmd, int *in, int *out);

void	env_append(char ***env, char *key, char *val);
char	*env_get(char **env, char *key);
char	*env_key(char *src);
int		env_key_exists(char **env, char *key);
int		env_key_validate(char *src, char *err_type, int unset);
void	clear_sl(char **env);
char	**env_dup(char **env, int clear);
char	*env_str(char *key, char *val);

void	bi_echo(int fd, char **argv);
void	bi_pwd(int fd);
void	bi_cd(int fd, t_shell *sh, t_cmd *cmd, int has_pipe);
void	bi_cd_after(t_shell *sh, t_cmd *cmd, char *oldpwd, int status);
void	bi_env(int *fds, t_cmd *cmd, char **env);
void	bi_export(int fd, t_shell *sh, t_cmd *cmd, int has_pipe);
void	bi_unset(t_shell *sh, t_cmd *cmd, int has_pipe);
void	bi_exit(t_shell *sh, t_cmd *cmd, int has_pipe);
int		mod256_from_str(char *s);
pid_t	run_with_env(int *fds, char **argv, char **env, int argv_i);
int		arg_is_option(char *arg, char option);

void	set_running(int val);
void	run(t_shell *sh);
void	non_interactive_run(t_shell *sh);
void	interactive_run(t_shell *sh);

#endif
