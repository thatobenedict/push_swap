/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:43:47 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/08 18:34:30 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	hard_sort2_b(t_ps *ps)
{
	if (check_sort_stack(ps->b) == 0)
		do_sb(ps);
	return ;
}

int		b_score(int i, t_stack *stack)
{
	int score;
	int diff;

	score = 0;
	if (i > stack->top / 2)
		diff = stack->top - i;
	else
		diff = i + 1;
	while (--diff >= 0)
	{
		if (i > stack->top / 2)
			score++;
		else
			score--;
	}
	return (score);
}

int		rot_score(t_stack *stack)
{
	int score;
	int diff;

	score = 0;
	if (ret_index(who_min(stack), stack) > stack->top / 2)
		diff = stack->top - ret_index(who_min(stack), stack);
	else
		diff = ret_index(who_min(stack), stack) + 1;
	while (--diff >= 0)
	{
		if (ret_index(who_min(stack), stack) > stack->top / 2)
			score++;
		else
			score--;
	}
	return (score);
}
/*
 ** =This function seeks to find out the true number of rotations required to achieve the correct pb
 */
int		real_rot(int a, int b)
{
	if (a < 0 && b < 0)
		return (ft_absdiff(ft_abs(a),ft_abs(b)) + ft_ismin(ft_abs(a),ft_abs(b)));
	else if (a > 0 && b > 0)
		return (ft_absdiff(a, b) + ft_ismin(a, b));
	else
		return (ft_abs(a) + ft_abs(b));
}

void	store_top(int a, int b, t_ps *ps)
{
	if (a < 0 && b < 0)
	{
		ps->tscore->mag = ft_ismin(ft_abs(a),ft_abs(b));
		ps->tscore->dir = -1;
		ps->tscore->mag_a = (ft_abs(a) > ft_abs(b)) ?
			ft_abs(a) - ft_abs(b) : 0;
		ps->tscore->mag_b = (ft_abs(b) > ft_abs(a)) ?
			ft_abs(b) - ft_abs(a) : 0;
		ps->tscore->dir_a = -1;
		ps->tscore->dir_b = -1;
	}
	else if (a > 0 && b > 0)
	{
		ps->tscore->mag = ft_ismin(ft_abs(a),ft_abs(b));
		ps->tscore->mag_a = (a > b) ? a - b : 0;
		ps->tscore->mag_b = (b > a) ? b - a : 0;
	}
	else
	{
		ps->tscore->mag_a = ft_abs(a);
		ps->tscore->mag_b = ft_abs(b);
		ps->tscore->dir_a = (a < 0) ? -1 : 0;
		ps->tscore->dir_b = (b < 0) ? -1 : 0;
	}
}

int		is_between(int i, int j, t_ps *ps)
{
		if (i == ps->b->top && who_max(ps->b) == ps->b->array[i])
		{
			if (ps->b->array[i] < ps->a->array[j])
				return (0);
		}
		else if (i == ps->b->top)
		{
				
		}
		else if ()
}

//remember to send the first two then sort them biggest to smallest
void	dynamic_sort(t_ps *ps)
{
	int i;
	int j;
	int score;

	do_pb(ps);
	do_pb(ps);
	//hard_sort2_b(ps);
	i = ps->b->top + 1;
	while (--i >= 0)
	{
		j = ps->a->top + 1;
		while (--j >= 0)
		{
			if (is_between(i, j, ps) == 0)
			{
				score = real_rot(rot_score(ps->a), b_score(i, ps->b));
				if (score < ps->score->top)
				{
					store_top();
					ps->score->top = score;
				}
			}			
		}
	}	
}
