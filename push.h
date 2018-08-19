/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:40:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/19 16:11:16 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

#include "get_next_line/get_next_line.h"

typedef struct	s_stack
{
	int			top;
	size_t		size;
	int			*array;
}				t_stack;

typedef struct  s_new_stack(size_t size)
{
	t_stack	*stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (int *)ft_memalloc(sizeof(int *) * stack->size);
	return (stack);
}				t_new_stack;



















# endif
