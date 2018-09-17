/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:43:47 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/15 17:52:51 by tbenedic         ###   ########.fr       */
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
** This function seeks to find out the true
** number of rotations required to achieve the correct pb
*/

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
		if (is_between(ps->b->array[i], ps->b->array[0],
					ps->a->array[j]) == 0)
			return (0);
	}
	else
	{
		if (is_between(ps->b->array[i], ps->b->array[i + 1],
					ps->a->array[j]) == 0)
			return (0);
	}
	return (1);
}

void	set_zero(t_ps *ps)
{
	ps->score.dir = 0;
	ps->score.dir_a = 0;
	ps->score.dir_b = 0;
}

void	store_top(int a, int b, t_ps *ps)
{
	if (a <= 0 && b <= 0)
	{
		ps->score.mag = ft_ismin(ft_abs(a), ft_abs(b));
		ps->score.mag_a = (ft_abs(a) > ft_abs(b)) ? ft_abs(a) - ft_abs(b) : 0;
		ps->score.mag_b = (ft_abs(b) > ft_abs(a)) ? ft_abs(b) - ft_abs(a) : 0;
		ps->score.dir = -1;
		ps->score.dir_a = -1;
		ps->score.dir_b = -1;
	}
	else if (a >= 0 && b >= 0)
	{
		ps->score.mag = ft_ismin(ft_abs(a), ft_abs(b));
		ps->score.mag_a = (a > b) ? a - b : 0;
		ps->score.mag_b = (b > a) ? b - a : 0;
		set_zero(ps);
	}
	else if ((a < 0 && b > 0) || (a > 0 && b < 0))
	{
		ps->score.dir = 0;
		ps->score.dir_a = (a < 0) ? -1 : 0;
		ps->score.dir_b = (b < 0) ? -1 : 0;
		ps->score.mag = 0;
		ps->score.mag_a = ft_abs(a);
		ps->score.mag_b = ft_abs(b);
	}
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
