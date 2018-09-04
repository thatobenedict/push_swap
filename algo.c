/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:22:25 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/01 15:28:19 by tbenedic         ###   ########.fr       */
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
	return (score);
}

int		who_max(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < array->top)
	{
		if (j < array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}

/*
** Return 1 if there is a cycle detected
** Return 0 if there is NO cycle detected
*/
int		check_cycle(t_stack *stack)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;;
	while (i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1] && j > 0)
			j++;
		if (stack->array[i] > stack->array[i + 1] && k > 0)
			k++;
		i++;
	}
	if (i == j + k)
		return (1);
	else
		return (0);
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
