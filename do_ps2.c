/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:56:28 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/07 14:53:51 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	do_ra(t_ps *stack)
{
	ft_ra(stack);
	ft_putstr("ra\n");
}

void	do_rb(t_ps *stack)
{
	ft_rb(stack);
	ft_putstr("rb\n");
}

void	do_rra(t_ps *stack)
{
	ft_rra(stack);
	ft_putstr("rra\n");
}

void	do_rrb(t_ps *stack)
{
	ft_rrb(stack);
	ft_putstr("rrb\n");
}
