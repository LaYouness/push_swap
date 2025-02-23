#include "libft/libft.h"
#include "push_swap.h"

int is_digits(char *str)
{
	if(*str == '+' || *str == '-')
		str++;
	if(*str == 0)
		return (0);
	while (*str)
	{
		if(ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
int	check_dup(t_stack *stack, long number)
{
	if (!stack)
		return (1);
	t_stack	*current;
	current = stack;
	while (current)
	{
		if(current->num == number)
			return(0);
		current = current->next;
	}
	return(1);
}
int	check_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if(current->num > current->next->num)
			return	(0);
		current++;
	}
	return(1);
}