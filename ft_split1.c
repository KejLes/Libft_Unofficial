/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:56:29 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/20 11:12:59 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_count(char *s, char c)
{
	size_t	i;
	size_t	words_count;

	i = 0;
	words_count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			words_count++;
		i++;
	}
	return (words_count);
}

char **ft_split(char const *s, char c)
{
	char	**ptr_strs;
	size_t	words_count;
		
	ptr_strs = malloc(words_count * sizeof(char *));
	
}