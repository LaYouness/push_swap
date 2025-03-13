#include "push_swap.h"

void    sort_3(t_stack **stack, char stack_name)
{
	t_stack	*max;
	t_stack	*current;

	max = *stack; 
	current = *stack;
	if (size_stack(*stack) == 2)
		return (sx(stack, stack_name));
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
void	element_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*element;
	int		raw_cost;

	element = stack_b;
	while (element)
	{
		if (element->index > size_stack(stack_b) / 2)
			element->cost_b = (size_stack(stack_b) - element->index) * -1;
		else
			element->cost_b = element->index;
		if (element->target > size_stack(stack_a) / 2)
			element->cost_a = (size_stack(stack_a) - element->target) * -1;
		else
			element->cost_a = element->target;
		raw_cost = absolute_value(element->cost_a) + absolute_value(element->cost_b);
		if (element->cost_a * element->cost_b > 0)
			element->cost = max_value(absolute_value(element->cost_a), absolute_value(element->cost_b));
		else
			element->cost = raw_cost;
		element = element->next;
	}
}
int	get_opti_elem(t_stack *stack)
{
	t_stack	*current;
	int		opti_cost;
	int		opti_index;

	opti_cost = INT_MAX;
	opti_index = INT_MAX;
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
void	para_rota(t_stack **stack_a, t_stack **stack_b, t_stack *element)
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
void	single_rota(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
	while (element->cost_a || element->cost_b)
	{
		if (element->cost_a > 0)
		{
			rx(stack_a, 'a');
			element->cost_a--;
		}
		else if (element->cost_a < 0)
		{
			rrx(stack_a, 'a');
			element->cost_a++;
		}

		if (element->cost_b > 0)
		{
			rx(stack_b, 'b');
			element->cost_b--;
		}
		else if (element->cost_b < 0)
		{
			rrx(stack_b, 'b');
			element->cost_b++;
		}
	}
}
void	b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current;
	int		opti_elem_index;
	while (size_stack(*stack_b))
	{
		set_targets(*stack_a, *stack_b);
		element_costs(*stack_a, *stack_b);
		opti_elem_index = get_opti_elem(*stack_b);
		current = *stack_b;
		while (current)
		{
			if (current->index == opti_elem_index)
				break;
			current = current->next;		
		}
		para_rota(stack_a, stack_b, current);
		single_rota(stack_a, stack_b, current);
		px(stack_b, stack_a, 'a');
	}
	stack_b = NULL;
}
void	final_rota(t_stack **stack, char stack_name)
{
	int		size;
	int		min;
	int		count;

	min = min_index(*stack);
	size = size_stack(*stack);
	if (min < size / 2)
	{
		count = min;
		while (count--)
			rx(stack, stack_name);
	}
	else if (min > size / 2)
	{
		count = size - min;
		while (count--)
			rrx(stack, stack_name);
	}
}
