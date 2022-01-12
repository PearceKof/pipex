/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:20:49 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/08 18:20:49 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void) {
//     const char* filename = "out.txt";

//     int fd = open(filename, O_WRONLY);
//     printf("fd = %d\n", fd);
//     if (fd == -1) {
//         perror("open");
//         exit(EXIT_FAILURE);
//     }
//     printf("fd = %d\n", fd);
//     ft_putchar_fd('p', fd);
//     printf("Done Writing!\n");

//     close(fd);
//     exit(EXIT_SUCCESS);
// }