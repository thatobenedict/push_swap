/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:22:25 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/09 11:30:14 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_absdiff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int		between(int a, int z, int x)
{
	if (a < z)
	{
		if (x > a && x < z)
			return (0);
		else
			return (1);
	}
	else
	{
		if (x > z && x < a)
			return (0);
		else
			return (1);
	}
}

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
**void	score_gen(int i_a, int i_b, t_ps *ps)
**{
**	int score;
**	int top_score;
**
**	score = i_a + i_b;
**	top_score = 100000000;
**	if (top_score > score)
**	{
**		top_score = score;
**		if (i_a < ps->a->mid)
**		{
**			ps->top.mag_a = i_a - ps->a->mid;
**			ps->top.dir_a = 1;
**		}
**		else
**			ps->top.mag_a = i_a - ps->a->mid;
**		if (i_b < ps->b->mid)
**		{
**			ps->top.mag_b = i_b - ps->b->mid;
**			ps->top.dir_b = 1;
**		}
**		else
**			ps->top.mag_b = i_a - ps->b->mid;
**	}
**}
** Return 1 if there is a cycle detected
** Return 0 if there is NO cycle detected
**int		check_cycle(t_stack *stack)
**{
**	int i;
**	int j;
**	int k;
**
**	i = 0;
**	j = 0;
**	k = 0;
**	while (i < stack->top)
**	{
**		if (stack->array[i] < stack->array[i + 1] && k > 0)
**			j++;
**		if (stack->array[i] > stack->array[i + 1] && j > 0)
**			k++;
**		i++;
**	}
**	if (i == j + k)
**		return (1);
**	else
**		return (0);
**}
**
**void	valid_rot(t_ps *ps)
**{
**	int i_a;
**	int i_b;
**
**	i_a = ps->a->top + 1;
**	i_b = ps->b->top + 1;
**	ps->a->mid = ((ps->a->top + 1) / 2);
**	ps->b->mid = ((ps->b->top + 1) / 2);
**	while (--i_b > 0)
**	{
**		i_a = ps->a->top + 1;
**		while (--i_a >= 0)
**		{
**			if (ps->a->array[i_a] < who_min(ps->b))
**			{
**				ps->top.mag_a = i_a;
**				ps->top.dir_a = 0;
**				ps->top.mag_b = ret_index(who_min(ps->b), ps->b);
**				return ;
**			}
**			else if (ps->a->array[i_a] > who_max(ps->b))
**			{
**				ps->top.mag_a = i_a;
**				ps->top.dir_a = 0;
**				ps->top.mag_b = ret_index(who_max(ps->b), ps->b);
**				return ;
**			}
**			else if (between(ps->b->array[i_b], ps->b->array[i_b - 1],
**						ps->a->array[i_a]) == 0)
**				score_gen(i_a, i_b, ps);
**		}
**	}
**}
*/
