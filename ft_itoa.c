/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:52:30 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/23 19:00:16 by kcanales         ###   ########.fr       */
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

static char	*calloc_ptr(int len, int flag_negative)
{
	char	*ptr_str;

	if (flag_negative == 0)
		ptr_str = ft_calloc(len + 1, 1);	//Aquí hacía (len + 1, sizeof(char *))
	else
	{
		ptr_str = ft_calloc(len + 1, 1);	//Aquí hacía (len + 2, sizeof(char *)) Haciendo el cambio, paco lo hace bien
	}
	if (!ptr_str)
		return (NULL);
	else
		return (ptr_str);
}

static void	make_final_ptr(char *ptr_str, long num, int i, int flag_negative)
{
	int	result;

	ptr_str[i--] = '\0';
	while (i >= 0)
	{
		result = num % 10;
		num = num / 10;
		ptr_str[i] = result + '0';
		i--;
		if (i == 0 && flag_negative == 1)
			break ;
	}
	if (flag_negative == 1)
		ptr_str[0] = '-';
}

char	*ft_itoa(int n)
{
	long	num;
	int		i;
	int		flag_negative;
	char	*ptr_str;

	num = n;
	flag_negative = 0;
	i = (int_len(num));
	if (num < 0)
	{
		flag_negative = 1;
		num = -num;
		i++;
	}
	ptr_str = calloc_ptr(i, flag_negative);
	if (!ptr_str)
		return (NULL);
	make_final_ptr(ptr_str, num, i, flag_negative);
	return (ptr_str);
}
/*
int	main(void)
{
	int a = -2147483648L;
	int	b = 100034;
	int	c = 0;
	int d = 2147483647;	//limite del valor en int

	char *i = ft_itoa(a);
	char *j = ft_itoa(b);
	char *k = ft_itoa(c);
	char *h = ft_itoa(d);

	printf("int original: %d\nft_itoa: %s\n\n", a, i);
	printf("int original: %d\nft_itoa: %s\n\n", b, j);
	printf("int original: %d\nft_itoa: %s\n\n", c, k);
	printf("int original: %d\nft_itoa: %s\n\n", d, h);

	free(i);
	free(j);
	free(k);
	free(h);
}
*/