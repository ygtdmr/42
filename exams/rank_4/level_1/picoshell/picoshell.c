#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#include <stdio.h>

static int	close_fd(int fd[2])
{
	if (fd[0] != -1)
	{
		close(fd[0]);
		fd[0] = -1;
	}
	if (fd[1] != -1)
	{
		close(fd[1]);
		fd[1] = -1;
	}
	return (1);
}

static int launch(int fd[2], char *file, char **argv)
{
	pid_t	pid;

	if (!(file && argv))
		return (0);
	pid = fork();
	if (pid == 0)
	{
		if (fd[0] != -1)
		{
			dup2(fd[0], 0);
			close(fd[0]);
		}
		if (fd[1] != -1)
		{
			dup2(fd[1], 1);
			close(fd[1]);
		}
		exit(execvp(file, argv) == -1);
	}
	else if (pid > 0)
	{
		wait(0);
		close_fd(fd);
		return (1);
	}
	else
		return (0);
}

int	picoshell(char **cmds[])
{
	char	*file;
	char	**argv;
	int		pipefd[2];
	int		fd[2];

	fd[0] = -1;
	fd[1] = -1;
	pipefd[0] = -1;
	pipefd[1] = -1;
	file = 0;
	argv = 0;
	while (*(*cmds))
	{
		if (!file)
			file = *(*cmds);
		if (!argv)
			argv = (*cmds);
		if (*(*cmds) && **(*cmds) == '|')
		{
			*(*cmds) = 0;
			if (fd[0] == -1)
				fd[0] = pipefd[0];
			if (pipe(pipefd) == -1)
				return (close_fd(pipefd));
			if (fd[1] == -1)
				fd[1] = pipefd[1];
			if (!launch(fd, file, argv))
				return (close_fd(pipefd));
			argv = 0;
			file = 0;
		}
		(*cmds)++;
	}
	fd[0] = pipefd[0];
	fd[1] = -1;
	if (!launch(fd, file, argv))
		return (close_fd(pipefd));
	close_fd(pipefd);
	return (0);
}

