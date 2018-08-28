/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:58:36 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 16:36:53 by tbenedic         ###   ########.fr       */
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
			ft_putnbr_fd(a->array[i], 2);
			ft_putchar_fd('\t', 2);
		}
		else
		{
			ft_putstr_fd("--", 2);
			ft_putchar_fd('\t', 2);
		}
		if (j >= 0)
		{
			ft_putnbr_fd(b->array[j], 2);
			ft_putchar_fd('\n', 2);
		}
		else
		{
			ft_putstr_fd("--", 2);
			ft_putchar_fd('\n', 2);
		}
		i--;
		j--;
	}
	ft_putstr_fd("--\t--\nA\tB\n", 2);
}

void	display_top(t_stack *ps)
{
	ft_putnbr(ps->top);
	ft_putchar('\n');
	ft_putnbr(ps->array[ps->top]);
	ft_putchar('\n');
}
