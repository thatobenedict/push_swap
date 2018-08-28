/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_inline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:58:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 16:48:29 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	assign(t_ps *ps)
{
	while (get_next_line(0, &(ps->gnl.line)) > 0)
	{
		if (ft_strcmp(ps->gnl.line,"sa") == 0)
			ft_sa(ps);
		else if (ft_strcmp(ps->gnl.line,"sb") == 0 )
			ft_sb(ps);
		else if (ft_strcmp(ps->gnl.line,"ss") == 0)
			ft_ss(ps);
		else if (ft_strcmp(ps->gnl.line,"pa") == 0)
			ft_pa(ps);
		else if (ft_strcmp(ps->gnl.line,"pb") == 0)
			ft_pb(ps);
		else if (ft_strcmp(ps->gnl.line,"ra") == 0)
			ft_ra(ps);
		else if (ft_strcmp(ps->gnl.line,"rb") == 0)
			ft_rb(ps);
		else if (ft_strcmp(ps->gnl.line,"rr") == 0)
			ft_rr(ps);
		else if (ft_strcmp(ps->gnl.line,"rra") == 0)
			ft_rra(ps);
		else if (ft_strcmp(ps->gnl.line,"rrb") == 0)
			ft_rrb(ps);
		else if (ft_strcmp(ps->gnl.line,"rrr") == 0)
			ft_rrr(ps);
		else if (ft_strcmp(ps->gnl.line,"") == 0)
			break ;
		display_stack(ps->a, ps->b);
	}
}
/*
void	operater(t_ps *ps)
{
	if ()
}*/
