/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaarare <ylaarare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:21:55 by ylaarare          #+#    #+#             */
/*   Updated: 2025/02/05 09:56:59 by ylaarare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!*lst)
		*lst = new;
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prec = current;
	new->next = NULL;
}
