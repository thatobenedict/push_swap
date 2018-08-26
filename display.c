/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:58:36 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/26 17:50:11 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	display_stack(t_ps *ps)
{
	int i;
	int j;

	i = ps->a.top;
	j = ps->b.top;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			ft_putnbr(ps->a.array[i]);
			ft_putchar('\t');
		}
		else
		{
			ft_putstr("--");
			ft_putchar('\t');
		}
		if (j >= 0)
		{
			ft_putnbr(ps->b.array[j]);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr("--");
			ft_putchar('\n');
		}
		i--;
		j--;
	}
	ft_putstr("--\t--\nA\tB\n");
}

void	display_top(t_stack *ps)
{
	ft_putnbr(ps->top);
	ft_putchar('\n');
	ft_putnbr(ps->array[ps->top]);
	ft_putchar('\n');
}
