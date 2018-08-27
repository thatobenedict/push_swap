/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:52:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/27 14:02:52 by tbenedic         ###   ########.fr       */
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
void	ft_pa(t_ps *stack)
{
	push(stack->a, stack->b->array[stack->b->top]);
	pop(stack->b);
}

void	ft_pb(t_ps *stack)
{
	push(stack->b, stack->a->array[stack->a->top]);
	pop(stack->a);
}
