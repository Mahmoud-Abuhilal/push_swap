/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:51:25 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/01 15:56:47 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **result, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**alo_str(char **result, char const *s, size_t words_count, char c)
{
	size_t	ptr_count;
	size_t	str_count;
	size_t	start_index;

	str_count = 0;
	ptr_count = 0;
	while (ptr_count < words_count)
	{
		while (s[str_count] == c && s[str_count] != '\0')
			str_count++;
		start_index = str_count;
		while (s[str_count] != c && s[str_count] != '\0')
			str_count++;
		result[ptr_count] = ft_substr(s, start_index, str_count - start_index);
		if (!result[ptr_count])
		{
			free_all(result, ptr_count);
			return (0);
		}
		ptr_count++;
	}
	return (result);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**result;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result = malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (0);
	if (!alo_str(result, s, words_count, c))
		return (0);
	result[words_count] = 0;
	return (result);
}
