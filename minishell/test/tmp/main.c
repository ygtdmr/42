/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:34:15 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/28 22:13:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

int exit_readline = 0;

void handle_sigint(int sig) {
    exit_readline = 1;
}

int main() {
    struct sigaction sa;
	ft_bzero(&sa, sizeof(struct sigaction));
    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    char *input;

    while (1) {
        // Eğer SIGINT sinyali aldıysak, readline'dan çık
        if (exit_readline) {
            printf("\nSIGINT sinyali alındı, readline'dan çıkılıyor...\n");
            break;
        }

        // readline ile giriş al
        input = readline("Komut girin: ");
        if (input != NULL) {
            printf("Girilen: %s\n", input);
            free(input);
        }
    }

    // Program devam ediyor, readline'dan çıkıldıktan sonra işlem yapılabilir.
    printf("Program devam ediyor...\n");

    return 0;
}
