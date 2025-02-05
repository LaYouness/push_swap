/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:14:11 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 19:44:00 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_from(const char *s1, const char *set)
{
	char	*s;

	s = (char *)s1;
	while (*s)
	{
		if (ft_strchr(set,*s))
			s++;
		else
			return (s);
	}
	return (s);
}

char	*find_to(const char *s1, const char *set)
{
	char	*end;
	size_t	sl;

	sl = ft_strlen((char *)s1);
	end = (char *)s1 + sl - 1;
	while (s1 != end)
	{
		if (ft_strchr(set, *end))
			end--;
		else
			return (end);
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*from;
	char	*to;
	char	*r;
	char	*o;
	size_t	size;

	if (!s1)
		return (NULL);
	from = find_from((char *)s1, (char *)set);
	if (*from == 0)
		return (ft_calloc(1, 1));
	to = find_to(from, (char *)set);
	size = to - from + 2;
	r = malloc(size);
	if (!r)
		return (NULL);
	o = r;
	while (size-- - 1)
		*r++ = *from++;
	*r = 0;
	return (o);
}
