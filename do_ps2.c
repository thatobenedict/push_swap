/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:56:28 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/06 12:55:09 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	do_ra(t_ps *stack)
{
	ft_ra(stack);
	ft_putstr_fd("ra\n", 2);
}

void	do_rb(t_ps *stack)
{
	ft_rb(stack);
	ft_putstr_fd("rb\n", 2);
}

void	do_rra(t_ps *stack)
{
	ft_rra(stack);
	ft_putstr_fd("rra\n", 2);
}

void	do_rrb(t_ps *stack)
{
	ft_rrb(stack);
	ft_putstr_fd("rrb\n", 2);
}
