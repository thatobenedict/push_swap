/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_6plus_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:28:26 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/11 18:41:11 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	if_rrr_store_top(int a, int b, t_ps *ps)
{
	ps->score.mag = ft_ismin(ft_abs(a), ft_abs(b));
	ps->score.mag_a = (ft_abs(a) > ft_abs(b)) ? ft_abs(a) - ft_abs(b) : 0;
	ps->score.mag_b = (ft_abs(b) > ft_abs(a)) ? ft_abs(b) - ft_abs(a) : 0;
	ps->score.dir = -1;
	ps->score.dir_a = -1;
	ps->score.dir_b = -1;
}

void	if_rr_store_top(int a, int b, t_ps *ps)
{
	ps->score.mag = ft_ismin(ft_abs(a), ft_abs(b));
	ps->score.mag_a = (a > b) ? a - b : 0;
	ps->score.mag_b = (b > a) ? b - a : 0;
	ps->score.dir = 0;
	ps->score.dir_a = 0;
	ps->score.dir_b = 0;
}

void	if_2directions_store_top(int a, int b, t_ps *ps)
{
	ps->score.dir = 0;
	ps->score.dir_a = (a < 0) ? -1 : 0;
	ps->score.dir_b = (b < 0) ? -1 : 0;
	ps->score.mag = 0;
	ps->score.mag_a = ft_abs(a);
	ps->score.mag_b = ft_abs(b);
}
