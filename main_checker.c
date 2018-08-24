/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/24 15:22:53 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int trig;
	t_stack *a;
	t_stack *b;

	if (ac == 2)
	{
		trig = 2;
		ac = ft_white_word_count(av[1]) + 1;
		av = ft_strsplit(av[1], ' ');
		ft_duplicates (av, ac - 1);
		is_digits(av, trig);
		is_int(av, trig);
	}
	else
	{
		trig = 1;
		ft_duplicates (av, ac);
		is_digits(av, trig);
		is_int(av, trig);
	}
	a = new_stack(ac - 1);
	b = new_stack(ac - 1);

	int i = ac - trig;
	while (i >= 0)
		push(a, ft_atoi(av[i--]));
	display_stack(a, b);
	return 0;
}
