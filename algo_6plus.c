/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:23:47 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/11 18:42:31 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ab_score(int i, t_stack *stack)
{
	int diff;

	if (i >= stack->top / 2)
		diff = stack->top - i;
	else
		diff = (-1) * (i + 1);
	return (diff);
}

/*
** This function seeks to find out the true number of rotations required
** to achieve the correct pb
*/

int		real_rot(int a, int b)
{
	if (a < 0 && b < 0)
		return (ft_absdiff(ft_abs(a), ft_abs(b)) +
				ft_ismin(ft_abs(a), ft_abs(b)));
	else if (a >= 0 && b >= 0)
		return (ft_absdiff(a, b) + ft_ismin(a, b));
	else
		return (ft_abs(a) + ft_abs(b));
}

int		is_valid(int i, int j, t_ps *ps)
{
	if (who_max(ps->b) == ps->b->array[i])
	{
		if (ps->b->array[i] < ps->a->array[j] ||
				who_min(ps->b) > ps->a->array[j])
			return (0);
	}
	else if (i == ps->b->top)
	{
		if (ft_is_between(ps->b->array[i], ps->b->array[0],
					ps->a->array[j]) == 0)
			return (0);
	}
	else
	{
		if (ft_is_between(ps->b->array[i], ps->b->array[i + 1],
					ps->a->array[j]) == 0)
			return (0);
	}
	return (1);
}

void	store_top(int a, int b, t_ps *ps)
{
	if (a < 0 && b < 0)
		if_rrr_store_top(a, b, ps);
	else if (a >= 0 && b >= 0)
		if_rr_store_top(a, b, ps);
	else
		if_2directions_store_top(a, b, ps);
}

void	sort_engine(t_ps *ps)
{
	int i;
	int j;
	int score;

	i = ps->b->top + 1;
	while (--i >= 0)
	{
		j = ps->a->top + 1;
		while (--j >= 0)
		{
			if (is_valid(i, j, ps) == 0)
			{
				score = real_rot(ab_score(j, ps->a), ab_score(i, ps->b));
				if (score < ps->score.top)
				{
					store_top(ab_score(j, ps->a), ab_score(i, ps->b), ps);
					ps->score.top = score;
					if (ps->score.top <= 1)
						return ;
				}
			}
		}
	}
}
