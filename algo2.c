/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:17:26 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/05 18:08:10 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	hard_sort3(t_ps *ps)
{
	int i;

	i = 0;
	if (who_min(ps->a) == 2 && who_max(ps->a) == 1)
	{
		ft_ra(ps);
		ft_putstr_fd("ra\n", 2);
	}
	else //(ret_index(who_min(ps->a)) == 2 && ret_index(who_max(ps->a)) == 1)
	{
		ft_rra(ps);
		ft_putstr_fd("rra\n", 2);
	}
	display_stack(ps->a, ps->b);
	exit (1);
}
/*
void	hard_sort5(t_ps *ps)
{
}*/
