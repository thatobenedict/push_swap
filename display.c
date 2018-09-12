/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:58:36 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/12 10:59:24 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	display_stack(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int fd;

	i = a->top + 1;
	j = b->top + 1;
	fd = 2;
	while (--i >= 0 || --j >= 0)
	{
		if (i >= 0)
		{
			ft_putnbr_fd(a->array[i], fd);
			ft_putchar_fd('\t', fd);
		}
		else
			ft_putstr_fd("--\t", fd);
		if (j >= 0)
		{
			ft_putnbr_fd(b->array[j], fd);
			ft_putchar_fd('\n', fd);
		}
		else
			ft_putstr_fd("--\n", fd);
	}
	ft_putstr_fd("--\t--\nA\tB\n", fd);
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
		ft_putstr_fd(UNSORTED, 2);
		exit(-1);
	}
	else if (signal == 1)
	{
		ft_putstr_fd(SORTED, 2);
		exit(-1);
	}
}

int		relieve_yourself(t_ps *ps)
{
	int i;

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
	if (ps->av != NULL)
	{
		i = -1;
		while (ps->av[++i] != 0)
			free(ps->av[i]);
		free(ps->av);
	}
	ft_memdel((void **)&ps);
	return (0);
}
