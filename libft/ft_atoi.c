/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:39:51 by ylaarare          #+#    #+#             */
/*   Updated: 2025/02/05 15:28:31 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	char	*p;
	int		sign;
	long	r;

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
