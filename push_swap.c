#include "push_swap.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	int 	i;
	char	**splited_arg;
	t_stack	*stack_a;

	if (ac <= 1)
		return (-1);
	stack_a = NULL;
	i = 1;
	/*creating stack*/
	while (i < ac)
	{
		splited_arg = split(av[i]);
		if(splited_arg[0] == 0)
			return(printf("Error\n"), -1);
		if(!add_to_stack(&stack_a, splited_arg))
			return(free_stack(stack_a), free_splited_args(splited_arg), printf("Error\n"), -1);
		free_splited_args(splited_arg);
		i++;
	}
	while (stack_a)
	{
		printf("%ld\n", stack_a->num);
		stack_a = stack_a->next;
	}
}
