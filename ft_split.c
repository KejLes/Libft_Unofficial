/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcanales <kcanales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:51:00 by kcanales          #+#    #+#             */
/*   Updated: 2025/05/26 16:22:55 by kcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c);
static void		put_in_word_list(const char *s, char c,	char **ptr_strs);
static void		free_arr_of_strs(char **arr, size_t words);
static int		check_null(char **ptr_strs, size_t words);

/*
int	main(void)
{
	char	**c;
	char	*s = "Hola!,,,,,,";
	char	CharDel = ',';
	
	size_t	words = words_count(s, CharDel);
	
	c = ft_split(s, CharDel);
	
	for (int i = 0; i < words; i++)	
		printf("%s\n", c[i]);
		
	free_arr_of_strs(c, words);
}
*/

char	**ft_split(char const *s, char c)
{
	char	**ptr_strs;
	size_t	words;

	words = words_count(s, c);
	ptr_strs = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!ptr_strs)
		return (NULL);
	put_in_word_list(s, c, ptr_strs);
	if (!check_null(ptr_strs, words))
		return (NULL);
	return (ptr_strs);
}

static int	check_null(char **ptr_strs, size_t words)
{
	size_t	j;

	j = 0;
	while (j < words)
	{
		if (ptr_strs[j] == NULL)
		{
			free_arr_of_strs(ptr_strs, words);
			return (0);
		}
		j++;
	}
	return (1);
}

static void	free_arr_of_strs(char **arr, size_t words)
{
	size_t	ifree;

	ifree = 0;
	while (ifree < words)
	{
		free(arr[ifree]);
		ifree++;
	}
	free(arr);
}

static void	put_in_word_list(const char *s, char c, char **ptr_strs)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			start = i;
			while ((s[i + 1] != c) && (s[i + 1] != '\0'))
				i++;
			ptr_strs[j] = ft_substr(s, (start), (i - start + 1));
			if (ptr_strs[j] == NULL)
				break ;
			j++;
		}
		i++;
	}
	ptr_strs[j] = NULL;
}

size_t	words_count(char const *s, char c)
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
