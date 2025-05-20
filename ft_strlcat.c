/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:08:18 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/16 16:29:15 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= len_dst)
		return (len_src + size);
	while ((len_dst + i) < (size - 1) && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
//    <<<<COMPROBACIÓN HECHA POR IA>>>>
// Debe hacerse la comprobación con un compilador online dado que la función
// strlcat no está en las librerias de c por defecto
// Con ayuda de la página:    https://github.com/edramir18/strlcat_demo

// Prototipo de tu función personalizada
size_t ft_strlcat(char *dst, const char *src, size_t size);

int main(void) {
	// Macros para simplificar la comparación y evitar repeticiones
	#define TEST_STRLCAT(num, dst_init, src, size) \
		do { \
			char buf_std[64] = dst_init; \
			char buf_ft[64]  = dst_init; \
			size_t res_std = strlcat(buf_std, src, size); \
			size_t res_ft  = ft_strlcat(buf_ft, src, size); \
			printf("%2d. strlcat(\"%s\", \"%s\", %zu) = %zu, \"%s\"\
										 | ft_strlcat = %zu, \"%s\"%s\n", \
				num, dst_init, src, size, res_std, buf_std, res_ft, buf_ft, \
				(res_std == res_ft && strcmp(buf_std, buf_ft) == 0)\
				? " [OK]" : " [!!]"); \
		} while(0)

	// 1-7: "", "" con size 0 o 1
	TEST_STRLCAT( 1, "", "", 0);
	TEST_STRLCAT( 2, "", "", 0);
	TEST_STRLCAT( 3, "", "", 0);
	TEST_STRLCAT( 4, "", "", 1);
	TEST_STRLCAT( 5, "", "", 0);
	TEST_STRLCAT( 6, "", "", 0);
	TEST_STRLCAT( 7, "", "", 1);

	// 8-14: "HOLA", "" con size 0,3,4,5
	TEST_STRLCAT( 8, "HOLA", "", 0);
	TEST_STRLCAT( 9, "HOLA", "", 3);
	TEST_STRLCAT(10, "HOLA", "", 4);
	TEST_STRLCAT(11, "HOLA", "", 5);
	TEST_STRLCAT(12, "HOLA", "", 3);
	TEST_STRLCAT(13, "HOLA", "", 4);
	TEST_STRLCAT(14, "HOLA", "", 5);

	// 15-21: "", "MUNDO" con size 0,1,4,5,6
	TEST_STRLCAT(15, "", "MUNDO", 0);
	TEST_STRLCAT(16, "", "MUNDO", 0);
	TEST_STRLCAT(17, "", "MUNDO", 0);
	TEST_STRLCAT(18, "", "MUNDO", 1);
	TEST_STRLCAT(19, "", "MUNDO", 4);
	TEST_STRLCAT(20, "", "MUNDO", 5);
	TEST_STRLCAT(21, "", "MUNDO", 6);

	// 22-28: "HOLA", "MUNDO" con size 0,3,4,5,8,9,10
	TEST_STRLCAT(22, "HOLA", "MUNDO", 0);
	TEST_STRLCAT(23, "HOLA", "MUNDO", 3);
	TEST_STRLCAT(24, "HOLA", "MUNDO", 4);
	TEST_STRLCAT(25, "HOLA", "MUNDO", 5);
	TEST_STRLCAT(26, "HOLA", "MUNDO", 8);
	TEST_STRLCAT(27, "HOLA", "MUNDO", 9);
	TEST_STRLCAT(28, "HOLA", "MUNDO", 10);

	#undef TEST_STRLCAT
	return 0;
}
*/