/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/24 08:57:37 by tbenedic         ###   ########.fr       */
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
	}
	else
	{
		trig = 1;
		ft_duplicates (av, ac);

	}
	a = new_stack(ac - 1);
	b = new_stack(ac - 1);

	int i = ac - trig;
	while (i >= 0)
		push(a, ft_atoi(av[i--]));
	display_stack(a, b);
	return 0;
}
