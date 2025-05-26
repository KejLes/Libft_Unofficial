/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:33:11 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/26 18:17:08 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	write(fd, n, int_len(n));
}

int	main(void)
{
	int	a = 13;
	ft_putnbr_fd(a, 1);
	printf("\n%d!\n", a);
}