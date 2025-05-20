/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:34:28 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/16 16:29:44 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr_strtrim;

	
	
	
}

#include <stdio.h>
#include <string.h>

char *ft_strtrim(const char *s1, const char *set) {
    size_t start = 0;
    size_t end = strlen(s1) - 1;

    // Eliminar los caracteres del principio
    while (s1[start] && strchr(set, s1[start]))
        start++;

    // Eliminar los caracteres del final
    while (end > start && strchr(set, s1[end]))
        end--;

    // Copiar la subcadena recortada
    size_t len = end - start + 1;
    char *result = malloc(len + 1);
    if (!result)
        return NULL;

    for (size_t i = 0; i < len; i++)
        result[i] = s1[start + i];
    
    result[len] = '\0'; // Asegurarse de que la cadena esté terminada

    return result;
}

int main() {
    const char *str = "  \t\nHola, Mundo! \n\t  ";
    const char *set = " \t\n";  // Espacios, tabulaciones y saltos de línea

    char *trimmed = ft_strtrim(str, set);
    printf("Cadena recortada: '%s'\n", trimmed);

    free(trimmed);
    return 0;
}
