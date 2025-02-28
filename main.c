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
	stack_ranking(stack_a);
	a_to_b(&stack_a, &stack_b);
	printf("stack B\n");
	current = stack_b;
	while (current)
	{
		printf("index: %d / value: %ld\n", current->index, current->num);
		current = current->next;
	}
	printf("stack A\n");
	current = stack_a;
	while (current)
	{
		printf("index: %d / value: %ld\n", current->index, current->num);
		current = current->next;
	}
	printf("min index a: %d\n", min_index(stack_a));
	printf("min index b: %d\n", min_index(stack_b));
	free_stack(stack_b);
	free_stack(stack_a);
}
