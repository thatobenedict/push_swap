/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2to5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:21:04 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/11 17:21:07 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotates(t_ps *ps)
{
	int diff;

	if (ret_index(who_min(ps->a), ps->a) > ps->a->top / 2)
		diff = ps->a->top - ret_index(who_min(ps->a), ps->a);
	else
		diff = ret_index(who_min(ps->a), ps->a) + 1;
	while (--diff >= 0)
	{
		if (ret_index(who_min(ps->a), ps->a) > ps->a->top / 2)
			do_ra(ps);
		else
			do_rra(ps);
	}
}

void	hard_sort2(t_ps *ps)
{
	if (check_sort_int(ps) == 0)
		exit(1);
	do_sa(ps);
}

void	hard_sort3(t_ps *ps)
{
	if (ret_index(who_min(ps->a), ps->a) == 0)
	{
		if (ret_index(who_max(ps->a), ps->a) == 2)
			do_sa(ps);
		do_rra(ps);
	}
	else if (ret_index(who_min(ps->a), ps->a) == 1)
	{
		if (ret_index(who_max(ps->a), ps->a) == 2)
			do_ra(ps);
		else
			do_sa(ps);
	}
	else
	{
		do_sa(ps);
		do_ra(ps);
	}
	if (ps->hard_trig == 0)
		exit(1);
	ps->hard_trig = 0;
}

void	hard_sort4_5(t_ps *ps)
{
	int i;

	i = -1;
	while (++i < ((ps->ac - 1) % 2) + 1)
	{
		rotates(ps);
		do_pb(ps);
	}
	ps->hard_trig = 1;
	if (check_sort_stack(ps->a) == 1)
		hard_sort3(ps);
	i = -1;
	while (++i < ((ps->ac - 1) % 2) + 1)
		do_pa(ps);
	if (ps->hard_trig == 0)
		exit(1);
	ps->hard_trig = 0;
}
