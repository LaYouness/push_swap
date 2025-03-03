#include "push_swap.h"
void	stack_indexig(t_stack *stack)
{
	int	i;

	if(!stack)
		return;
	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}
int	size_stack(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return(size);
}
void    free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*hold_next;

	current = stack;
	while (current)
	{
		hold_next = current->next;
		free(current);
		current = hold_next;
	}
}
void free_splited_arg(char	**words)
{
	int i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}
int	add_to_stack(t_stack **stack_a, char **splited_arg)
{
	int		j;
	int		number;
	t_stack	*new_elem;

	j = 0;
	while (splited_arg[j])
	{
		if(is_digits(splited_arg[j]) == 0)
			return(0);
		number = atoi(splited_arg[j]);
		if(number > INT_MAX || number < INT_MIN || !check_dup(*stack_a, number))
			return(0);
		new_elem = lstnew(number);
		if(!new_elem)
			return(0);
		lstadd_back(stack_a, new_elem);
		j++;
	}
	return(1);
}

t_stack	*create_stack(int ac, char **av)
{
	int 	i;
	char	**splited_arg;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		splited_arg = split(av[i]);
		if(splited_arg[0] == 0)
			return(free_splited_arg(splited_arg), NULL);
		if(!add_to_stack(&stack_a, splited_arg))
			return(free_stack(stack_a), free_splited_arg(splited_arg), NULL);
		free_splited_arg(splited_arg);
		i++;
	}
	stack_indexig(stack_a);
	stack_ranking(stack_a);
	return (stack_a);
}
void	a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		half_size;
	int		i;
	t_stack	*current;

	half_size = size_stack(*stack_a) / 2;
	i = half_size;
	while (i)
	{
		if((*stack_a)->position <= half_size)
			px(stack_a, stack_b, 'b');
		else
			rx(stack_a, 'a');
		--i;
	}
	while (size_stack(*stack_a) > 3)
		px(stack_a, stack_b, 'b');
	sort_3(stack_a, 'a');
	print_stacks(*stack_a, *stack_b);
}
int	min_index(t_stack *stack)
{
	t_stack	*current;
	int		rank;
	
	current = stack;
	rank = current->position;
	while (current)
	{
		if(current->position < rank)
			rank = current->position;
		current = current->next;
	}
	while (stack)
	{
		if (stack->position == rank)
			return(stack->index);
		stack = stack->next;
	}
	return(-1);
}
int	absolute_value(int num)
{
    if (num < 0)
        return -num;
    else
        return num;
}
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	printf("stack A\n");
	current = stack_a;
	while (current)
	{
		printf("index: %d / value: %ld / target: %d / cost a: %d / cost b: %d / cost: %d\n", current->index, current->num, current->target, current->cost_a, current->cost_b, current->cost);
		current = current->next;
	}
	printf("stack B\n");
	current = stack_b;
	while (current)
	{
		printf("index: %d / value: %ld / target: %d / cost a: %d / cost b: %d / cost: %d\n", current->index, current->num, current->target, current->cost_a, current->cost_b, current->cost);
		current = current->next;
	}
}