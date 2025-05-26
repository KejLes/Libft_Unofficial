/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:27:01 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/26 16:58:22 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	to_up(unsigned int i, char c)
// {
// 	(void) i;
// 	printf("%c\n", c);
// 	if (c >= 'a' && c <= 'z')
// 		c = c - 32;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*ptr_mapi;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ptr_mapi = (char *)ft_calloc((len + 1), sizeof(char));
	if (!ptr_mapi)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr_mapi[i] = f(i, s[i]);
		i++;
	}
	ptr_mapi[i] = '\0';
	return (ptr_mapi);
}

// int	main(void)
// {
// 	char str[] = "hello world";
// 	char *str1 = ft_strmapi(str, to_up);
// 	printf("%s\n", str1);
// 	free (str1);
// }