/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:13:43 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/14 19:41:49 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sl;
	size_t	subsize;
	char	*substr;
	char	*filler;

	if (!s)
		return (NULL);
	sl = ft_strlen((char *)s);
	if (start >= sl)
		return (ft_calloc(1, 1));
	if (len <= sl - start)
		subsize = len + 1;
	else
		subsize = sl - start + 1;
	substr = malloc(subsize);
	if (!substr)
		return (NULL);
	filler = substr;
	while (subsize-- - 1 && *(s + start))
		*filler++ = *(s + start++);
	*filler = 0;
	return (substr);
}
