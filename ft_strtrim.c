/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:34:28 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/21 15:20:41 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	loop_en_verse(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	loop_inverse(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = (ft_strlen((char *)s1) - 1);
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				start;
	int				len;

	if (!s1 || !set)
		return (NULL);
	start = loop_en_verse(s1, set);
	len = (loop_inverse(s1, set) - start + 1);
	return (ft_substr(s1, start, len));
}

// int main() {	
//     const char *str = " lorem ipsum dolor sit amet";
//     const char *set = " l";
// 	// const char *set = "\t\n ";  // Espacios, tabulaciones y saltos de línea

//     char *trimmed = ft_strtrim(str, set);
//     printf("Cadena recortada: '%s'\n", trimmed);

//     free(trimmed);
//     return 0;
// }
