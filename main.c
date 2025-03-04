#include "push_swap.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	int 	i;
	char	**splited_arg;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*current;

	stack_b = NULL;
	if (ac <= 1)
		return (0);
	stack_a = create_stack(ac, av);
	if (!stack_a)
		return (printf("Error!\n"), 0);
	if (check_sorted(stack_a))
		return(0);
	
	print_stacks(stack_a, stack_b);

	a_to_b(&stack_a, &stack_b);
	
	print_stacks(stack_a, stack_b);

	b_to_a(&stack_a, &stack_b);

	print_stacks(stack_a, stack_b);

	if (!check_sorted(stack_a))
	{
		final_rota(&stack_a, 'a');
		print_stacks(stack_a, stack_b);
	}
	free_stack(stack_a);
}
