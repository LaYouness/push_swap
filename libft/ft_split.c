/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:08:25 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 20:03:27 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cw(char *s, char c)
{
	size_t	now;

	now = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			now++;
			while (*s && *s != c)
				s++;
		}
		while (*s == c)
			s++;
	}
	return (now);
}

static size_t	low(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

static void	free_all(char **start, char **end)
{
	while (start <= --end)
		free(*end);
	free(start);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**word_to_word;
	size_t	now;
	size_t	wl;

	if (!s)
		return (NULL);
	now = cw((char *)s, c);
	arr = ft_calloc((now + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	word_to_word = arr;
	while (now--)
	{
		while (*s == c)
			s++;
		wl = low((char *)s, c);
		*word_to_word = malloc(wl + 1);
		if (!*word_to_word)
			return (free_all(arr, word_to_word), NULL);
		ft_strlcpy(*word_to_word, s, wl + 1);
		s = s + wl;
		word_to_word++;
	}
	return (arr);
}
