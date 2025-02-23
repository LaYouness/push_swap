#include "push_swap.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	int 	i;
	char	**splited_arg;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (-1);
	stack_a = create_stack(ac, av);
	if (!stack_a)
		return (printf("Error!\n"), 0);	
	
	free_stack(stack_a);
}
