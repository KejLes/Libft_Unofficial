/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:37:45 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/26 16:22:15 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/**
// No hay misterio
int	main(void)
{
	int i;
	char	c[] = "Hola Mundo";
	
	ft_putchar_fd(c[0], 1);

	printf("\n");
	
	for (i = 0; c[i] != '\0'; i++)
	{
		printf("%c", c[i]);
	}
	
}
*/