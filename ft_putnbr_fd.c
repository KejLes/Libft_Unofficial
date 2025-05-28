/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:41:20 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/28 14:44:16 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	power(long int a);
static long int	int_len(long int n);

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		intprint;

	ln = (long int)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	while (int_len(ln) > 1)
	{
		intprint = ((ln / power(int_len(ln) - 1)) + 48);
		write(fd, &intprint, 1);
		ln = ln % power((int_len(ln) - 1));
	}
	intprint = (ln + 48);
	write(fd, &intprint, 1);
}

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
	long int	i;

	i = 1;
	while (a != 0)
	{
		i = i * 10;
		a--;
	}
	return (i);
}

/*
int	main(void)
{
	int	a = -2147483647;
	ft_putnbr_fd(a, 1);
	printf("\n%d!\n\n", a);

	int b = -2147483648;
	ft_putnbr_fd(b, 1);
	printf("\n%d!\n\n", b);

	int c = 0;
	ft_putnbr_fd(c, 1);
	printf("\n%d!\n\n", c);

	int d = 1;
	ft_putnbr_fd(d, 1);
	printf("\n%d!\n\n", d);

	int e = -0;
	ft_putnbr_fd(e, 1);
	printf("\n%d!\n\n", e);
}
*/