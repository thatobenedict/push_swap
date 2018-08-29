/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/29 18:00:28 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

void	creator(t_ps *ps, int ac, char **av)
{
	int i;

	i = ac - ps->trig;
	while (i >= 0)
	{
		push(ps->a, ft_atoi(av[i]));
		i--;
	}
	display_stack(ps->a, ps->b);
	apply(ps);
	check_sort(ps);
	display_stack(ps->a, ps->b);
}

int		main(int ac, char **av)
{
	t_ps	*ps;

	ps = ft_memalloc(sizeof(t_ps));
	ft_initial(ps);
	if (ft_strcmp(av[1],"-v") == 0 || ft_strcmp(av[2], "-c") == 0 ||
				ft_strcmp(av[2],"-v") == 0 || ft_strcmp(av[1], "-c") == 0)
	{
		if (ft_strcmp(av[1],"-v") == 0 || ft_strcmp(av[2], "-v") == 0)
			ps->flag.x = 1;
		if (ft_strcmp(av[1],"-c") == 0 || ft_strcmp(av[2], "-c") == 0)
			ps->flag.y = 1;  //to be removed to a separate function
	}
	if (ac == 2 + ps->flag.x + ps->flag.y)
	{
		ps->trig = 2;
		ac = ft_white_word_count(av[1 + ps->flag.x + ps->flag.y]) + 1;
		av = ft_strsplit(av[1 + ps->flag.x + ps->flag.y], ' ');
		err_admin(ac - 1, av, ps);
	}
	else
	{
		ps->trig = 1;
		err_admin(ac, av, ps);
	}
	ps->a = new_stack(ac - 1);
	ps->b = new_stack(ac - 1);
	creator(ps, ac, av);
	return (0);
}
