#include "push_swap.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	int 	i;
	int		j;
	char	**splited_arg;
	long	number;
	t_stack	*stack_a;
	t_stack	*new_elem;

	if (ac <= 1)
		return (-1);
	i = 1;
	while (i < ac)
	{
		splited_arg = split(av[i]);
		j = 0;
		while (splited_arg[j])
		{
			if(is_digits(splited_arg[j]) == 0)
				return(-1); /* need to free stack when failing L:31, 34, 37 */
			number = atoi(splited_arg[j]);
			if(number > INT_MAX || number < INT_MIN || !check_dup(stack_a, number))
				return(-1);
			new_elem = lstnew(number);
			if(!new_elem)
				return (-1);
			lstadd_back(&stack_a, new_elem);
			j++;
		}
		/* need to free splited arg after each loop */
		i++;
	}
	for (size_t i = 0; stack_a; i++)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
}
