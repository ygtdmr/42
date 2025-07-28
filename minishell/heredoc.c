/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 06:18:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/28 08:20:33 by yidemir          ###   ########.fr       */
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

static char	*get_line_heredoc(void)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (isatty(0))
		return (readline("> "));
	else
	{
		line = get_next_line(0);
		if (!line)
			return (0);
		tmp = ft_calloc(ft_strlen(line) - 1, sizeof(char *));
		while (!(line[i] == '\n' && !line[i + 1]))
		{
			tmp[i] = line[i];
			i++;
		}
		free(line);
		return (tmp);
	}
}

static void	heredoc(t_shell *sh, char *eof, int *pipefd)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = get_line_heredoc();
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

static void	next_line_after_hd(char *eof)
{
	char	*line;

	line = get_line_heredoc();
	while (line && !str_match(line, eof))
		line = get_line_heredoc();
	free(line);
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
		if (cmd->last_status > 0)
			return (-2);
		next_line_after_hd(eof);
		return (pipefd[0]);
	}
	return (-1);
}

