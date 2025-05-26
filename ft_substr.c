/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:32:07 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/26 14:39:48 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr_substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= (unsigned int)len_s)
		len = 0;
	else if (len > (len_s - start))
		len = (len_s - start);
	ptr_substr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr_substr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr_substr[i] = (char)s[start + i];
		i++;
	}
	ptr_substr[i] = '\0';
	return (ptr_substr);
}
/*
    // <<<Esta es la función de un compañero, hice una comparativa en el main>>>
char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	len_s;
	size_t	characters_left;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s || s == NULL || *s == 0)
		return (ft_strdup(""));
	characters_left = len_s - start;
	if (len > characters_left)
		len = characters_left;
	buffer = malloc(len + 1);
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}

int main(void)
{
	const char str[] = 		"123456789012345";

	// const char str[] = 		NULL;
	
	unsigned int start = 	4;
	size_t	len = 			5;

	char *substr = ft_substr("ABCDEF", 2, 3);
	char *substr2 = ft_substr2("ABCDEF", 2, 3);
	printf("str: <%s>\nsubstr: <%s>\n", str, substr);
	printf("str: <%s>\nsubstr2: <%s>\n", str, substr2);
	free (substr);
	free (substr2);
	return (0);
}
*/