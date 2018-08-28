/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:03:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 10:55:47 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*
 **	####ROTATE (A only and B only)
 ** ra : rotate a - shift up all elements of stack a by 1.
 ** The first element becomes the last one.
 ** rb : rotate b - shift up all elements of stack b by 1.
 ** The first element becomes the last one.
*/

void	ft_ra(t_ps	*stack)
{
	int i;
	int j;
	int temp;

	i = stack->a->top;
	j = 0;
	temp = stack->a->array[stack->a->top];
	while (i > 0)
	{
		stack->a->array[stack->a->top - j] =
			stack->a->array[stack->a->top - (j + 1)];
		i--;
		j++;
	}
	stack->a->array[0] = temp;
}

void	ft_rb(t_ps	*stack)
{
	int i;
	int j;
	int temp;

	i = stack->b->top;
	j = 0;
	temp = stack->b->array[stack->b->top];
	while (i > 0)
	{
		stack->b->array[stack->b->top - j] =
			stack->b->array[stack->b->top - (j + 1)];
		i--;
		j++;
	}
	stack->b->array[0] = temp;
}

/*
** ####REVERSE ROTATE (A only and B only)
** rra : reverse rotate a - shift down all elements of stack a by 1. 
** The flast element becomes the first one.
** rrb : reverse rotate b - shift down all elements of stack b by 1.
** The flast element becomes the first one.
*/

void	ft_rra(t_ps	*stack)
{
	int i;
	int j;
	int temp;

	i = stack->a->top;
	j = 0;
	temp = stack->a->array[0];
	while (i > 0)
	{
		stack->a->array[j] =
			stack->a->array[j + 1];
		i--;
		j++;
	}
	stack->a->array[stack->a->top] = temp;
}

void	ft_rrb(t_ps	*stack)
{
	int i;
	int j;
	int temp;

	i = stack->b->top;
	j = 0;
	temp = stack->b->array[0];
	while (i > 0)
	{
		stack->b->array[j] =
			stack->b->array[j + 1];
		i--;
		j++;
	}
	stack->b->array[stack->b->top] = temp;
}
