#include "push_swap.h"

void    sx(t_stack **stack, char stack_name)
{
	swap(stack);
	stack_indexig(*stack);
	printf("s%c\n", stack_name);
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	stack_indexig(*stack_a);
	stack_indexig(*stack_b);
	printf("ss\n");
}
void	px(t_stack **push_from, t_stack **push_to, char stack_name)
{
	push(push_from, push_to);
	stack_indexig(*push_from);
	stack_indexig(*push_to);
	printf("p%c\n", stack_name);
}
void	rx(t_stack **stack, char stack_name)
{
	rotate(stack);
	stack_indexig(*stack);
	printf("r%c\n", stack_name);
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	stack_indexig(*stack_a);
	stack_indexig(*stack_b);
	printf("rr\n");
}
void	rrx(t_stack **stack, char stack_name)
{
	rrotate(stack);
	stack_indexig(*stack);
	printf("rr%c\n", stack_name);
}
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	stack_indexig(*stack_a);
	stack_indexig(*stack_b);
	printf("rrr\n");
}