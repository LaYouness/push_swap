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
void	element_costs(t_stack *stack_a, t_stack *stack_b, t_stack *element)
{
	t_stack	*current;

	if (element->index > size_stack(stack_b) / 2)
		element->cost_b = (size_stack(stack_b) - element->index) * -1;
	else
		element->cost_b = element->index;
	if (element->target > size_stack(stack_a) / 2)
		element->cost_a = (size_stack(stack_a) - element->target) * -1;
	else
		element->cost_a = element->target;
	if (current->cost_a * current->cost_b > 0)
		current->cost = absolute_value(current->cost_a - current->cost_b);
	else
		current->cost = absolute_value(current->cost_a) + absolute_value(current->cost_b);
}
int	get_opti_elem(t_stack *stack)
{
	t_stack	*current;
	int		raw_cost;
	int		opti_cost;
	int		opti_index;

	opti_cost = current->cost;
	opti_index = 0;
	current = stack;
	while (current)
	{
		if (current->cost < opti_cost)
		{
			opti_cost = current->cost;
			opti_index = current->index;
		}
		current = current->next;
	}
	return (opti_index);
}
void	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current;
	int		opti_elem_index;

	current = *stack_b;
	while (current)
	{
		current->target = element_target(*stack_a, current);
		element_costs(*stack_a, *stack_b, current);
		current = current->next;
	}
	opti_elem_index = get_opti_elem(*stack_b);
	current = *stack_b;
	while (current)
	{
		if (current->index == opti_elem_index)
			break;
		current = current->next;		
	}
	while (current->cost_a < 0 && current->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		current->cost_a++;
		current->cost_b++;
	}
	while (current->cost_a > 0 && current->cost_b > 0)
	{
		rr(stack_a, stack_b);
		current->cost_a--;
		current->cost_b--;
	}
	while (current->cost_a)
	{
		if (current->cost_a > 0)
			rx(stack_a, 'a');
		else
			rrx(stack_a, 'a');
	}
	
}
