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
	t_stack	*element;

	current = stack;
	element = stack;
	while (current)
	{
		current->position = 1;
		current = current->next;
	}
	while (element)
	{
		current = stack;
		while (current->next)
		{
			if(element->num > current->next->num)
				++element->position;
			current = current->next;
		}
		element = element->next;
	}
}
int	element_target(t_stack *stack, t_stack *element)
{
	t_stack	*current;
	int		target_index;


	target_index = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->num > element->num && current->num < target_index)
			target_index = current->index;
		current = current->next;
	}
	if (target_index == INT_MAX)
		return (min_index(stack));
	return (target_index);
}
int	cost_a(t_stack *stack, t_stack *element)
{
	t_stack	*current;
	int		target;

	target = element->target;
	if (target > size_stack(stack) / 2)
		return(size_stack(stack) - target);
	else
		return(target);
}
int	cost_b(t_stack *stack, t_stack *element)
{
	if(element->index > size_stack(stack) / 2)
		return (size_stack(stack) - element->index);
	else
		return (element->index);
}
void	element_cost(t_stack *stack_a, t_stack *stack_b, t_stack *element)
{
	t_stack	*current;
	int		target;

	target = element->target;
	if (target > size_stack(stack_a) / 2)
		element->cost_a = size_stack(stack) - target);
	else
		return(target);
}
void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current;

	current = stack_b;
	while (current)
	{
		current->target = element_target(stack_a, current);
		current->cost_a = cost_a(stack_a, current);
		current->cost_b = 
	}
	
}