#include "push_swap.h"

void    swap(t_stack **stack)
{
	t_stack *first;
	t_stack *sec;

	first = (*stack);
	if (!*stack || !(*stack)->next)
		return;
	sec = (*stack)->next;
	first->next = sec->next;
	if (sec->next)
		sec->next->prev = first;
	sec->next = first;
	first->prev = sec;
	sec->prev = NULL;
	*stack = sec;
}
void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*holder;

	if (!*stack_a)
		return;
	holder = *stack_a;
	if ((*stack_a)->next)
		(*stack_a)->next->prev = NULL;
	*stack_a = (*stack_a)->next;
	if(!*stack_b)
	{
		*stack_b = holder;
		holder->next = NULL;
	}
	else
	{
		holder->next = *stack_b;
		(*stack_b)->prev = holder;
		*stack_b = holder;
	}
}
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
void	rrotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	*stack = last;
}
