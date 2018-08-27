/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/27 08:51:49 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_ps	*ps;
	
	ps = ft_memalloc(sizeof(t_ps));
	ps->trig = 0;
	if (ac == 2)
	{
		ps->trig = 2;
		ac = ft_white_word_count(av[1]) + 1;
		av = ft_strsplit(av[1], ' ');
		ft_duplicates (av, ac - 1);
		is_digits(av, ps);
		is_int(av, ps);
	}
	else
	{
		ps->trig = 1;
		ft_duplicates (av, ac);
		is_digits(av, ps);
		is_int(av, ps);
	}
	ps->a = new_stack(ac - 1);
	ps->b = new_stack(ac - 1);

	int i = ac - ps->trig;
	while (i >= 0)
	{

	push(ps->a, ft_atoi(av[i--]));
	}
	display_stack(ps->a, ps->b);
	return 0;
}
