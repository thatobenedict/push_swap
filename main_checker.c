/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/24 17:20:41 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int			 i;
	t_stack 	*a;
	t_stack 	*b;
	t_admin		*admin;

	error_handle(av, ac)
	if (ac == 2)
	{
		trig = 2;
		ac = ft_white_word_count(av[1]) + 1;
		av = ft_strsplit(av[1], ' ');
		error_handle(av, trig, ac - 1);
	}
	else
	{
		trig = 1;
		error_handle(av, trig, ac - 1);
	}
	a = new_stack(ac - 1);
	b = new_stack(ac - 1);
	i = ac - trig;
	while (i >= 0)
		push(a, ft_atoi(av[i--]));
	display_stack(a, b);


	return (0);
}
