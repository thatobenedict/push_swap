/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:09:06 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/26 18:18:26 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int			 i;
	t_ps		*ps;

	ps = ft_memalloc(sizeof(t_ps));
	error_handle(av, ac - 1, ps);
	ps->a = new_stack(ac - 1);
	ps->b = new_stack(ac - 1);
	i = ac - ps->admin.in_type;
	while (i >= 0)
		push(&(ps->a), ft_atoi(av[i--]));
	display_stack(ps);


	return (0);
}
