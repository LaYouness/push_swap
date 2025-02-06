#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct			stack
{
		long			num;
		struct stack	*next;
		struct stack	*prev;
} 						t_stack;

t_stack	*lstnew(long number);
void	lstadd_back(t_stack **lst, t_stack *new_node);
int		check_dup(t_stack *stack, long number);
int 	is_digits(char *str);
char	**split(char *str);


#endif