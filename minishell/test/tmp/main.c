/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:34:15 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/01 18:48:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../expand.h"

#include <stdlib.h>
#include <readline/readline.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	char *t = "test child";
	printf("TEST DENEME\n");
	pid_t pid = fork();

	if (pid == 0) {
		printf("result=%s\n", t);
		printf("CHILD process. PID: %d, Parent PID: %d\n", getpid(), getppid());
		// char *args[] = {"/bin/echo", "Merhaba çocuk işlemden!", NULL};
        // execve(0, args, 0);
		// printf("not found executable file\n");
	} else if (pid > 0) {
		printf("PARENT process. PID: %d, Child PID: %d\n", getpid(), pid);
		int status;
		waitpid(pid, &status, 0);
		printf("PARENT process: Child process %d has finished. exit status: %d\n", pid, status);
	} else {
		perror("fork failed");
	}

	return 0;
}

