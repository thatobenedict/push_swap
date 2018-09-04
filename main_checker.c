/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:31:25 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/04 15:08:51 by tbenedic         ###   ########.fr       */
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
	check_creator(ps, ac, av);
	return (0);
}
