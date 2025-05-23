/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:15:20 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/23 15:42:04 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	to_up(unsigned int i, char *c)
// {
// 	printf("%c", *c);
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char str[] = "hello world";
// 	printf("<");
// 	ft_striteri(str, to_up);
// 	printf(">");
// 	printf("\n%s\n", str);
// }