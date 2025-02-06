#include "push_swap.h"
#include "libft/libft.h"

t_stack	*lstnew(long number)
{
	t_stack	*head;

	head = ft_calloc(sizeof(t_stack),1);
	if (!head)
		return (NULL);
	head->num = number;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*current;

	if (!*lst)
		*lst = new_node;
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	new_node->next = NULL;
}
