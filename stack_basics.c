/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 07:35:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/07 17:01:45 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack		*new_stack(size_t size)
{
	t_stack	*ps;

	ps = (t_stack*)ft_memalloc(sizeof(t_stack));
	ps->size = size;
	ps->top = -1;
	ps->array = (int *)ft_memalloc(sizeof(int *) * ps->size);
	return (ps);
}

/*
**   new_stack function returns;
** - One 			if the stack is full,
** - Negative One	if the stack is empty and
** - Zero			otherwise.
*/

int			stack_state(t_stack *ps)
{
	if (ps->top == (int)(ps->size - 1))
		return (1);
	else if (ps->top == -1)
		return (-1);
	else
		return (0);
}

void		push(t_stack *ps, int integer)
{
	if (stack_state(ps) == 1)
		return ;
	ps->array[++ps->top] = integer;
}

int			pop(t_stack *ps)
{
	if (stack_state(ps) == -1)
		return (-1);
	return (ps->array[ps->top--]);
}

int			ret_index(int value, t_stack *stack)
{
	int i;

	i = 0;
	while (i <= stack->top)
	{
		if (value == stack->array[i])
			return (i);
		i++;
	}
	return (-1);
}
