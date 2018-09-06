/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ps1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 09:27:01 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/06 12:53:43 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	do_sa(t_ps *stack)
{
	ft_sa(stack);
	ft_putstr_fd("sa\n", 2);
}

void	do_sb(t_ps *stack)
{
	ft_sb(stack);
	ft_putstr_fd("sb\n", 2);
}

void	do_ss(t_ps *stack)
{
	ft_ss(stack);
	ft_putstr_fd("ss\n", 2);
}

void	do_pa(t_ps *stack)
{
	ft_pa(stack);
	ft_putstr_fd("pa\n", 2);
}

void	do_pb(t_ps *stack)
{
	ft_pb(stack);
	ft_putstr_fd("pb\n", 2);
}
