/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 06:18:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/29 14:45:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void expand_heredoc(t_shell *sh, char **line)
{
	char	*out;
	int 	length;

	out = 0;
	length = 0;
	while (*line && (*line)[length])
	{
		if ((*line)[length] == '$')
		{
			out = str_lrealloc(out, *line, length, 0);
			str_lclean(line, length + 1);
			length = 0;
			var_append(sh, line, &out, 0);
		}
		else
			length++;
	}
	out = str_lrealloc(out, *line, length, 1);
	*line = out;
}

static char	*get_line_heredoc(t_shell *sh)
{
	char	*line;
	int		length;

	if (sh->prompt)
	{
		length = ft_strlen(sh->prompt);
		if (ft_strchr(sh->prompt, '\n'))
			length = length - ft_strlen(ft_strchr(sh->prompt, '\n'));
		line = str_lrealloc(0, sh->prompt, length, 0);
		line = str_lrealloc(line, "\n", 1, 0);
		str_lclean(&sh->prompt, length);
		printf("line => %s\n", line); // gives \n\n its reason of why ending loop.
		return (line);
	}
	else
		return (readline("> "));
}

static void	heredoc(t_shell *sh, char *eof, int *pipefd)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = get_line_heredoc(sh);
		if (!line)
		{
			ft_putendl_fd("minishell: warning: \
here-document delimited by end-of-file", 1);
			break ;
		}
		if (str_match(line, eof))
			break ;
		expand_heredoc(sh, &line);
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	if (line)
		free(line);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(0);
}

static void	clear_prompt(t_shell *sh, char *eof)
{
	int length;

	if (!sh->prompt)
		return ;
	length = ft_strlen(sh->prompt);
	if (ft_strnstr(sh->prompt, eof, length))
		length = length - ft_strlen(ft_strnstr(sh->prompt, eof, length));
	str_lclean(&sh->prompt, length);
}

int	get_heredoc_fd(t_shell *sh, t_cmd *cmd, char *eof)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (-3);
	pid = fork();
	if (pid == 0)
		heredoc(sh, eof, pipefd);
	else if (pid > 0)
	{
		g_running = 1;
		waitpid(pid, &cmd->last_status, 0);
		g_running = 0;
		close(pipefd[1]);
		clear_prompt(sh, eof);
		if (cmd->last_status > 0)
			return (-2);
		return (pipefd[0]);
	}
	return (-1);
}

