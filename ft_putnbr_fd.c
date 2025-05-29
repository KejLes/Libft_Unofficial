/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:49:06 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/29 12:34:18 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ten_power_i(long int a);
static long int	int_len(long int n);
static void		check_zeros(long int last_ln, long int ln, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		intprint;
	long int	last_ln;

	ln = (long int)n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	while (int_len(ln) > 1)
	{
		intprint = ((ln / ten_power_i(int_len(ln) - 1)) + 48);
		write(fd, &intprint, 1);
		last_ln = ln;
		ln = ln % ten_power_i((int_len(ln) - 1));
		check_zeros(last_ln, ln, fd);
	}
	intprint = (ln + 48);
	write(fd, &intprint, 1);
}

static void	check_zeros(long int last_ln, long int ln, int fd)
{
	long int	len_last_ln;
	long int	len_ln;
	int			izero;

	len_last_ln = int_len(last_ln);
	len_ln = int_len(ln);
	if (len_last_ln != (len_ln + 1))
	{
		izero = (len_last_ln - 1) - len_ln;
		while (izero)
		{
			write(fd, "0", 1);
			izero--;
		}
	}
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

static long int	ten_power_i(long int a)
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
//Quise hacerlo por mi mismo 
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

	int f = -100001;
	ft_putnbr_fd(f, 1);
	printf("\n%d!\n\n", f);
}
*/

/* Esta es otra forma de hacerlo, solo que lo mío 
no es la recursividad
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
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