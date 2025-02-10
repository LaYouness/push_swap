#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct			stack
{
		long			num;
		struct stack	*next;
		struct stack	*prev;
} 						t_stack;

void    free_stack(t_stack *stack);
t_stack	*lstnew(long number);
void	lstadd_back(t_stack **lst, t_stack *new_node);
int		check_dup(t_stack *stack, long number);
int 	is_digits(char *str);
char	**split(char *str);
int		add_to_stack(t_stack **stack_a, char **splited_arg);
void	free_splited_args(char	**words);

#endif