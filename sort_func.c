#include "push_swap.h"

void    sort_3(t_stack **stack, char stack_name)
{
	t_stack	*max;
	t_stack	*current;

	max = *stack; 
	current = *stack;
	while (current)
	{
		if(current->num > max->num)
			max = current;
		current = current->next;
	}
	if(max->index == 0)
		rx(stack, stack_name);
	else if(max->index == 1)
		rrx(stack, stack_name);
	if((*stack)->num > (*stack)->next->num)
		sx(stack, stack_name);
}
void	stack_ranking(t_stack *stack)
{
	t_stack *current;
	t_stack	*compare;

	current = stack;
	compare = stack;
	while (current)
	{
		current->position = 1;
		current = current->next;
	}
	while (compare)
	{
		current = stack;
		while (current->next)
		{
			if(compare->num > current->next->num)
				++compare->position;
			current = current->next;
		}
		compare = compare->next;
	}
}
