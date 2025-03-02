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
void	set_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		target_index;
	int		target_value;

	while (stack_b)
	{
	target_index = INT_MAX;
	target_value = INT_MAX;
	current = stack_a;
	while (current)
	{
		if (current->num > stack_b->num && current->num < target_value)
		{
			target_index = current->index;
			target_value = current->num;
		}
		current = current->next;
	}
	if (target_index == INT_MAX)
		stack_b->target = min_index(stack_a);
	else
		stack_b->target = target_index;
	stack_b = stack_b->next;
	}
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
void	para_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
	while (element->cost_a < 0 && element->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		element->cost_a++;
		element->cost_b++;
	}
	while (element->cost_a > 0 && element->cost_b > 0)
	{
		rr(stack_a, stack_b);
		element->cost_a--;
		element->cost_b--;
	}
}
void	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current;
	int		opti_elem_index;

	set_targets(stack_a, stack_b);
	opti_elem_index = get_opti_elem(*stack_b);
	current = *stack_b;
	while (current)
	{
		if (current->index == opti_elem_index)
			break;
		current = current->next;		
	}
	para_rotate(stack_a, stack_b, current);
	while (current->cost_a)
	{
		if (current->cost_a > 0)
			rx(stack_a, 'a');
		else
			rrx(stack_a, 'a');
	}
	while (current->cost_b)
	{
		if (current->cost_b > 0)
			rx(stack_b, 'b');
		else
			rrx(stack_b, 'b');
	}
}
