/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younessla <younessla@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:39:51 by ylaarare          #+#    #+#             */
/*   Updated: 2024/11/13 09:07:25 by younessla        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		sign;
	int		r;

	r = 0;
	sign = 1;
	p = (char *)nptr;
	while ((*p >= 9 && *p <= 13) || *p == 32)
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = -1;
		p++;
	}
	while (ft_isdigit(*p))
		r = r * 10 + (*p++ - 48);
	return (r * sign);
}
