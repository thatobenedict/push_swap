/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:09:29 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/16 08:40:07 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	hard_sort2_b(t_ps *ps)
{
	if (check_sort_stack(ps->b) == 0)
		do_rb(ps);
	if (who_max(ps->b) < ps->a->array[ps->a->top] ||
				who_min(ps->b) > ps->a->array[ps->a->top])
		return ;
	else
		do_rb(ps);
}

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

int		real_rot(int a, int b)
{
	if (a <= 0 && b <= 0)
		return (ft_absdiff(ft_abs(a), ft_abs(b)) +
				ft_ismin(ft_abs(a), ft_abs(b)));
	else if (a >= 0 && b >= 0)
		return (ft_absdiff(a, b) + ft_ismin(a, b));
	else if ((a < 0 && b > 0) || (a > 0 && b < 0))
		return (ft_abs(a) + ft_abs(b));
	else
		return (0);
}
