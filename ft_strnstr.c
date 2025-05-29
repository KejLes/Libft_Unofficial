/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:38:05 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/29 15:06:58 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little [j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (little[j] == '\0')
			return ((char *)(big + i - j + 1));
		i++;
	}
	return (NULL);
}

//     <<<<<<<<<<<<<<<<HECHO CON IA>>>>>>>>>>>>>>>>> 
//No lo comparo con la función original
//Lo estoy comparando con una replica hecha por otro estudiante de 42 
//Esto es debido a que no hay lib en c predeterminada que 
//tenga la función strnstr
/*
char	*ftft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}


// Función auxiliar para mostrar el resultado (NULL o string encontrado)
const char *show_result(char *res) {
    return res ? res : "NULL";
}

int main(void)
{
    struct {
        const char *haystack;
        const char *needle;
        size_t len;
    } tests[] = {
        {"Hello world", "world", 11},
        {"Hello world", "world", 5},
        {"Hello world", "", 11},
        {"", "", 0},
        {"abcdef", "def", 6},
        {"abcdef", "def", 5},
        {"abcdef", "xyz", 6},
        {"abcabcabc", "abc", 9},
        {"abcabcabc", "abc", 2},
        {"abcabcabc", "cab", 7},
        {"aaabcabcd", "abcd", 9},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < num_tests; i++) {
        char *res1 = ft_strnstr(tests[i].haystack, tests[i].needle,
				 tests[i].len);
        char *res2 = ftft_strnstr(tests[i].haystack, tests[i].needle,
				 tests[i].len);

        printf("Test %d: haystack=\"%s\", needle=\"%s\", len=%zu\n", 
               i+1, tests[i].haystack, tests[i].needle, tests[i].len);
        printf("  ft_strnstr:     %s\n", show_result(res1));
        printf("  ftft_strnstr:   %s\n", show_result(res2));

        if (res1 == res2 || (res1 && res2 && strcmp(res1, res2) == 0))
            printf("  Resultado: OK\n\n");
        else
            printf("  Resultado: ERROR\n\n");
    }
    return 0;
}
*/