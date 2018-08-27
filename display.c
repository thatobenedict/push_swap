/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:58:36 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/27 09:53:55 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	display_stack(t_stack *a, t_stack *b)
{
	int i;
	int j;

	i = a->top;
	j = b->top;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			ft_putnbr(a->array[i]);
			ft_putchar('\t');
		}
		else
		{
			ft_putstr("--");
			ft_putchar('\t');
		}
		if (j >= 0)
		{
			ft_putnbr(b->array[j]);
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
