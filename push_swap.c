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
	t_stack *cursor;
	printf("stack a:\n");
	cursor = stack_a;
	while (cursor)
	{
		printf("%ld\n", cursor->num);
		cursor = cursor->next;
	}
	printf("swap a:\n");
	swap(&stack_a);
	cursor = stack_a;
	while (cursor)
	{
		printf("%ld\n", cursor->num);
		cursor = cursor->next;
	}
	printf("rotate a:\n");
	rotate(&stack_a);
	cursor = stack_a;
	while (cursor)
	{
		printf("%ld\n", cursor->num);
		cursor = cursor->next;
	}
	printf("rrotate a:\n");
	rrotate(&stack_a);
	cursor = stack_a;
	while (cursor)
	{
		printf("%ld\n", cursor->num);
		cursor = cursor->next;
	}
	free_stack(stack_a);
}
