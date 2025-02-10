#include "push_swap.h"

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
void free_splited_args(char	**words)
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
