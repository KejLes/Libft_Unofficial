/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:33:11 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/28 14:06:45 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_putnbr_fd(int n, int fd)
{
	int	nb;

	nb = (int)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd('0' + nb % 10, fd);
	}
	else
		ft_putchar_fd('0' + nb, fd);
}
*/

static long int	int_len(long int n)
{
	long int	i;

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

static long int	power(long int a)
{
	long int i;

	i = 1;
	while (a != 0)
	{
		i = i * 10;
		a--;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	ln;
	char		intprint;
	long int	a, b, c, d;

	ln = (long long int)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	while (ln != 0)
	{
		a = int_len(ln) - 1;
		b = power(a);
		c = ln /b;
		d = c + 48;
		intprint = d;//((n/(10 * (int_len(n) - 1))) + 48);
		write(fd, &intprint, 1);
		ln = ln % (b);
		if (ln < 10)
		{
			intprint = (ln + 48);
			write(fd, &intprint, 1);
			break;
		}
	}
}

int	main(void)
{
	// int	a = -214748364;
	int a = -2147483648;
	ft_putnbr_fd(a, 1);
	printf("\n%d!\n", a);
}