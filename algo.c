/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:22:25 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/31 16:57:06 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		between(int a, int z, int x)
{
	if (a > z)
	{
		if (x < a && x > z)
			return (0);
		else
			return (1);
	}
	else
	{
		if (x > a && x < z)
			return (0);
		else
			return (1);
	}
}

int		score_gen(int i_a, int i_b, t_ps *ps)
{
	int score;
	int pretend_to_compile = ps->trig;

	pretend_to_compile = 0;
	score = i_a + i_b;
}

void		valid_rot(t_ps *ps) // remember to make look pretty / clearer / you're assuming odd for now
{
	int i_a;
	int i_b;
	int top_score;
	int score;

	i_a = ps->b->top;
	i_b = ps->b->top;
	top_score = 0;
	score = 0;
	ps->a->mid = (ps->a->top / 2);
	ps->b->mid = (ps->b->top / 2);

	while (i_b > 0)
	{
		ps->a->mid = (ps->a->top / 2);
		while (i_a >= 0)
		{
			if (between(ps->b->array[i_b], ps->b->array[i_b - 1],
						ps->a->array[i_a]) == 0)
			{
				score = score_gen(i_a, i_b, ps);
				if (top_score > score)
				{
					top_score = score;
					if (i_a < ps->a->mid)
					{
						ps->top.mag_a = i_a - ps->a->mid + 1;
						ps->top.dir_a = 1;
					}
					else
					{
						ps->top.mag_a = i_a - ps->a->mid;
						ps->top.dir_a = 0;
					}
					if (i_b < ps->b->mid)
					{
						ps->top.mag_b = i_b - ps->b->mid + 1;
						ps->top.dir_b = 1;
					}
					else
					{
						ps->top.mag_b = i_a - ps->b->mid;
						ps->top.dir_a = 0;
					}
					ps->top.dir_a = ps->b->mid;
					ps->top.dir_b = ps->b->mid;
				}	
			}
			i_a--;
		}
		i_b--;
	}
}

/*
   void	sort_10(t_ps *ps)
   {
   int i;

   i = 0;
   if (ps->a->top == 2)
   {
   while (check_sort_int(ps) == 1)
   {
   }
   }
   }*/
// GET THE GENERAL SOLUTION GOING FIRST BUB,
// THEN  DIG INTO THE PARTICULAR SOLUTION
