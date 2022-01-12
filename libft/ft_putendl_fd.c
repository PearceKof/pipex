/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:23:06 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:26:12 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int main(void)
// {
//     const char* filename = "out.txt";

//     int fd = open(filename, O_WRONLY);
//     printf("fd = %d\n", fd);
//     if (fd == -1) {
//         perror("open");
//         exit(EXIT_FAILURE);
//     }
//     printf("fd = %d\n", fd);
//     ft_putendl_fd("test", fd);
//     printf("Done Writing!\n");

//     close(fd);
//     exit(EXIT_SUCCESS);
// }