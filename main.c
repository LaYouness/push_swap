#include "push_swap.h"
#include "libft/libft.h"

int main(int ac, char **av)
{	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac <= 1)
		return (0);
	stack_a = create_stack(ac, av);
	if (!stack_a)
		return (write(2, "Error!\n", 6), 0);
	if (check_sorted(stack_a))
		return(free_stack(stack_a), 0);
	if (size_stack(stack_a) <= 3)
	{
		sort_3(&stack_a, 'a');
		return (0);
	}
	a_to_b(&stack_a, &stack_b);
	b_to_a(&stack_a, &stack_b);
	if (!check_sorted(stack_a))
		final_rota(&stack_a, 'a');
	free_stack(stack_a);
}
