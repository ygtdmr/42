#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	pid_t	pid;
	int		pipefd[2];

	if (!(file && argv && (type == 'r' || type == 'w')))
		return (-1);
	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		if (type == 'r')
			dup2(pipefd[1], 1);
		if (type == 'w')
			dup2(pipefd[0], 0);
		close(pipefd[1]);
		close(pipefd[0]);
		exit(execvp(file, argv) == -1);
	}
	else if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	if (type == 'r')
	{
		close(pipefd[1]);
		return (pipefd[0]);
	}
	if (type == 'w')
	{
		close(pipefd[0]);
		return (pipefd[1]);
	}
	return (-1);
}

int main()
{
	char	bf[1024];
	size_t	len;
	int		fd;
	// char	*args[] = {"ls", "-l", NULL};
	
	// fd = ft_popen("/bin/ls", args, 'r');
	// printf("current fd => %d\n", fd);
	// while (read(fd, bf, 1024) > 0)
	// 	printf("%s", bf);

	char	*args[] = {"grep", "main", NULL};
	
	fd = ft_popen("/bin/grep", args, 'w');
	printf("current fd => %d\n", fd);
	write(fd, "T#include <stdio.h>\nint main() { return 0; }\n", 45);

	return (0);
}
