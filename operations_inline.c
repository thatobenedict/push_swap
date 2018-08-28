/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_inline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:58:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 15:41:39 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	assign(t_ps *ps)
{
	while (get_next_line(0, &(ps->gnl.line)) > 0)
	{
		if (ft_strcmp(ps->gnl.line,"sa"))
			ft_sa(ps);
		else if (ft_strcmp(ps->gnl.line,"sb"))
			ft_sb(ps);
		else if (ft_strcmp(ps->gnl.line,"ss"))
			ft_ss(ps);
		else if (ft_strcmp(ps->gnl.line,"pa"))
			ft_pa(ps);
		else if (ft_strcmp(ps->gnl.line,"pb"))
			ft_pb(ps);
		else if (ft_strcmp(ps->gnl.line,"ra"))
			ft_ra(ps);
		else if (ft_strcmp(ps->gnl.line,"rb"))
			ft_rb(ps);
		else if (ft_strcmp(ps->gnl.line,"rr"))
			ft_rr(ps);
		else if (ft_strcmp(ps->gnl.line,"rra"))
			ft_rra(ps);
		else if (ft_strcmp(ps->gnl.line,"rrb"))
			ft_rrb(ps);
		else if (ft_strcmp(ps->gnl.line,"rrr"))
			ft_rrr(ps);
	}
}
void	operater(t_ps *ps)
{
	if ()
}
