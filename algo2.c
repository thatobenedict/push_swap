/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:17:26 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/06 13:00:33 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
	int j;
	int k;

	i = 0;
	while (i < ((ps->ac - 1) % 2) + 1)
	{
		j = 0;
		k = ret_index(who_min(ps->a), ps->a);
		while (j <= k)
		{
			do_rra(ps);
			j++;
		}
		do_pb(ps);
		i++;
	}
	ps->hard_trig = 1;
	hard_sort3(ps);
	do_pa(ps);
	do_pa(ps);
	if (ps->hard_trig == 0)
		exit(1);
	ps->hard_trig = 0;
}
