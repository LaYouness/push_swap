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
	while (stack)
	{
		if(stack->num == number)
			return(0);
		stack = stack->next;
	}
	return(1);
}