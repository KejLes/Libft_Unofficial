/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:01:35 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/21 16:27:00 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned const char	*str1;
	unsigned const char	*str2;

	i = 0;
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	if (!n)
		return (0);
	while ((i != (n - 1)) && (str1[i] != '\0') && (str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
/*
int	main()
{
	char str1[] = "abcdefgh";
	char str2[] = "abcdwxyz";
	size_t	n = 4;
	int	funcionft = ft_strncmp(str1, str2, n);
	int	funcion = strncmp(str1, str2, n);
	//printf("\"%d\"\n\"%d\"\n", (int)str1[i], (int)str2[i]);  
	//Colocar dentro de ft_strncmp, antes del ultimo return
	
	printf("Return ft_strncmp: %d\n", funcionft);
	printf("Return strncmp(): %d\n", funcion);
}*/