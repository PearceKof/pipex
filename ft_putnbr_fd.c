/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:27:26 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:45:23 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nbr = nb * -1;
	}
	else
	{
		nbr = nb;
	}
	if (nbr <= 9)
		ft_putchar_fd(nbr + '0', fd);
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <unistd.h>
// int	main(void)
// {
// 	const char* filename = "out.txt";
// 	int	fd = open(filename, O_WRONLY);
// 	printf("fd = %d\n", fd);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	printf("fd = %d\n", fd);
// 	ft_putnbr_fd(-2147483648, fd);
// 	printf("Done Writing!\n");
// 	close(fd);
// 	exit(EXIT_SUCCESS);
// }