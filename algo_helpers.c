/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:58:21 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/12 09:42:28 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		who_min(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->array[0];
	while (i <= array->top)
	{
		if (j > array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}

int		who_max(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->array[0];
	while (i <= array->top)
	{
		if (j < array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}

/*
** Designed primarily for sorting of 6 and above elements
** i.e. algo2.c
** Sorts elements in the B stack in descending order
*/

void	hard_sort2_b(t_ps *ps)
{
	if (check_sort_stack(ps->b) == 0)
		do_rb(ps);
	return ;
}

/*
** Designed primarily for sorting of 6 and above elements
** i.e. algo2.c
** Rotates Stack B sufficiently enough to move the maximum element ...
** ... to the top of the stack
*/

void	b_max_to_top(t_ps *ps)
{
	int diff;

	if (ret_index(who_max(ps->b), ps->b) >= ps->b->top / 2)
		diff = ps->b->top - ret_index(who_max(ps->b), ps->b);
	else
		diff = ret_index(who_max(ps->b), ps->b) + 1;
	while (--diff >= 0)
	{
		if (ret_index(who_max(ps->b), ps->b) >= ps->b->top / 2)
			do_rb(ps);
		else
			do_rrb(ps);
	}
}

void	push_b_reset_score(t_ps *ps)
{
	do_pb(ps);
	ps->score.top = 1000;
	ps->score.mag_a = 0;
	ps->score.mag_b = 0;
	ps->score.dir_a = 0;
	ps->score.dir_b = 0;
	ps->score.mag = 0;
	ps->score.dir = 0;
}
