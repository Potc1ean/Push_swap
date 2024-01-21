#include "push_swap.h"

/*reverse_rotate:
*   Brings the bottom element of the stack to the top.
static void	rev_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    tail = get_stack_bottom(*stack);
    tmp = get_stack_before_bottom(*stack);
    tail->next = *stack;
    tmp->next = NULL;
    *stack = tmp;
    // a revoir si ca marche 
}
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/* do_rra:
*	Brings the bottom element of stack a to the top.
*	Prints "rra" to the standard output.
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/* do_rrb:
*	Brings the bottom element of stack b to the top.
*	Prints "rrb" to the standard output.
*/
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/* do_rrr:
*	Brings the bottom element of both stack a and stack be
*	to the top of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}