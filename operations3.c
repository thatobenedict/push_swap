/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:23:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 11:51:00 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*
** ####ROTATE & REVERSE ROTATE (Both A & B)
** rr : ra and rb at the same time.
** rrr : rra and rrb at the same time.
*/

void ft_rr(t_ps *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}

void ft_rrr(t_ps *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}
