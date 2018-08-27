/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:52:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/27 12:22:31 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*
** ### SWAP ###
** sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
** is only one or no elements.
** sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
** is only one or no elements.
** ss : sa and sb at the same time.
*/

void	ft_sa(t_ps *stack)
{
	if (stack->a->top >= 1)
		ft_swap(&stack->a->array[stack->a->top], 
				&stack->a->array[stack->a->top - 1]);
}

void	ft_sb(t_ps *stack)
{
	if (stack->b->top > 1)
	ft_swap(&stack->b->array[stack->b->top], 
			&stack->b->array[stack->b->top - 1]);
}

void	ft_ss(t_ps *stack)
{
	if (stack->a->top > 1 && stack->b->top > 1)
	{
		ft_swap(&stack->a->array[stack->a->top], 
				&stack->a->array[stack->a->top - 1]);	
		ft_swap(&stack->b->array[stack->b->top], 
			&stack->b->array[stack->b->top - 1]);
	}
}

//####PUSH
// pa : push a - take the first element at the top of b and put it at the top of a. Do
//nothing if b is empty.
// pb : push b - take the first element at the top of a and put it at the top of b. Do
//nothing if a is empty.

/////////// you need to pre-error check before calling these guy indepently
void	ft_pa(t_stack *ps)
{
	push(stack->a->top, stack->b->array[stack->b->top]);
	pop(stack->b->top);
}

void	ft_pb(t_stack *ps)
{
	push(stack->b->top, stack->a->array[stack->a->top]);
	pop(stack->a->top);
}


//####ROTATE
// ra : rotate a - shift up all elements of stack a by 1. The first element becomes
//the last one.
// rb : rotate b - shift up all elements of stack b by 1. The first element becomes
//the last one.
// rr : ra and rb at the same time.

//####REVERSE ROTATE
// rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
//becomes the first one.
// rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
//becomes the first one.
// rrr : rra and rrb at the same time.
