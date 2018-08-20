/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 07:35:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/20 08:59:48 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

ps->stack		*new_stack(t_ps	*ps, size_t size)
{
	ps	*new_stack;

	new_stack = (ps->stack *)ft_memalloc(sizeof(ps->stack));
	ps->stack->size = size;
	ps->stack->top = -1;
	ps->stack->array = (int *)ft_memalloc(sizeof(int *) * ps->stack->size);
	return (new_stack);
}
/*
**   new_stack function returns;
** - One 			if the stack is full,
** - Negative One	if the stack is empty and
** - Zero			otherwise.
*/
int		stack_state(t_ps *ps)
{
	if (ps->stack->top == (int)ps->stack->size - 1)
		return (1);
	else if (ps->stack->top == -1)
		return (-1);
	else
		return (0);
}
/*
void	push(t_ps *ps)
{
	if (stack_state(ps->stack) == )
}

void	pop(t_ps *ps)
{
}*/
