/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:31:25 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/07 14:38:48 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	check_creator(t_ps *ps, int ac, char **av)
{
	int i;

	i = ac - ps->trig;
	while (i >= 0)
	{
		push(ps->a, ft_atoi(av[i]));
		i--;
	}
	apply(ps);
	check_sort(ps);
}

int		main(int ac, char **av)
{
	t_ps	*ps;

	ps = ft_memalloc(sizeof(t_ps));
	ft_initial(ps);
	if (ac == 2)
	{
		ps->trig = 2;
		ac = ft_white_word_count(av[1]) + 1;
		av = ft_strsplit(av[1], ' ');
		err_admin(ac - 1, av, ps);
	}
	else
	{
		ps->trig = 1;
		err_admin(ac, av, ps);
	}
	ps->a = new_stack(ac - 1);
	ps->b = new_stack(ac - 1);
	check_creator(ps, ac, av);
	return (0);
}
