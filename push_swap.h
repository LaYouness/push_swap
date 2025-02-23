#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct			stack
{
		long			num;
		int				index;
		int				position;
		struct stack	*next;
		struct stack	*prev;
} 						t_stack;

void	stack_indexig(t_stack *stack);
int		size_stack(t_stack *stack);
void    free_stack(t_stack *stack);
t_stack	*lstnew(long number);
void	lstadd_back(t_stack **lst, t_stack *new_node);
int 	is_digits(char *str);
char	**split(char *str);
int		add_to_stack(t_stack **stack_a, char **splited_arg);
void	free_splited_arg(char	**words);
t_stack	*create_stack(int ac, char **av);

int		check_dup(t_stack *stack, long number);
int		check_sorted(t_stack *stack);

void    swap(t_stack **stack);
void	push(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);

void    sx(t_stack **stack, char stack_name);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	px(t_stack **push_from, t_stack **push_to, char stack_name);
void	rx(t_stack **stack, char stack_name);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrx(t_stack **stack, char stack_name);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void    sort_3(t_stack **stack, char stack_name);
void	stack_ranking(t_stack *stack);
void	a_to_b(t_stack **stack_a, t_stack **stack_b);

#endif