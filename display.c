/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:58:36 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/16 10:40:54 by tbenedic         ###   ########.fr       */
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
			ft_putstr_fd("--\t", 2);
		if (j >= 0)
		{
			ft_putnbr_fd(b->array[j], 2);
			ft_putchar_fd('\n', 2);
		}
		else
			ft_putstr_fd("--\n", 2);
		i--;
		j--;
	}
	ft_putstr_fd("--\t--\nA\tB\n", 2);
}

void	message(int signal)
{
	if (signal == -1)
	{
		ft_putstr_fd(ERROR, 2);
		exit(-1);
	}
	if (signal == -2)
		ft_putstr_fd(ERROR, 2);
	else if (signal == 0)
	{
		ft_putstr_fd(UNSORTED, 1);
		exit(-1);
	}
	else if (signal == 1)
	{
		ft_putstr_fd(SORTED, 1);
		exit(-1);
	}
}

int		relieve_yourself(t_ps *ps)
{
	if (ps->a != NULL)
	{
		if (ps->a->array != NULL)
			free(ps->a->array);
		ft_memdel((void **)&ps->a);
	}
	if (ps->b != NULL)
	{
		if (ps->b->array != NULL)
			free(ps->b->array);
		ft_memdel((void**)&ps->b);
	}
	ft_memdel((void **)&ps);
	return (0);
}
