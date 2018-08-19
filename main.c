/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/19 18:21:29 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ps->stack		*new_stack(t_ps	*ps, size_t size)
{
	ps	*new_stack;

	new_stack = (ps->stack *)ft_memalloc(sizeof(ps->stack));
	ps->stack->size = size;
	ps->stack->top = -1;
	ps->stack->array = (int *)ft_memalloc(sizeof(int *) * ps->stack->size);
	return (new_stack);
}
