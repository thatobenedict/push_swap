/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:44:05 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/04 18:37:21 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	make_play(int j, int k, t_ps *ps)
{
	if (ps->top.dir_a == 1 && ps->top.dir_b == 1)
	{
		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
			ft_rr(ps);
	}
	if (ps->top.dir_a == 0 && ps->top.dir_b == 0)
	{
		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
			ft_rrr(ps);
	}
	if (ps->top.dir_a == 0)
	{
		while (++j < ps->top.mag_a)
			ft_rra(ps);
	}
	else if (ps->top.dir_a == 1)
	{
		while (++j < ps->top.mag_a)
			ft_ra(ps);
	}
	if (ps->top.dir_b == 0)
	{
		while (++j < ps->top.mag_b)
			ft_rrb(ps);
	}
	else if (ps->top.dir_b == 1)
	{
		while (++j < ps->top.mag_b)
			ft_rb(ps);
	}
}

void	print_play(int j, int k, t_ps *ps)
{
	if (ps->top.dir_a == 1 && ps->top.dir_b == 1)
	{
		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
			ft_putstr_fd("rr\n", 2);
	}
	if (ps->top.dir_a == 0 && ps->top.dir_b == 0)
	{
		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
			ft_putstr_fd("rrr\n", 2);
	}
	if (ps->top.dir_a == 0)
	{
		while (++j < ps->top.mag_a)
			ft_putstr_fd("rra\n", 2);
	}
	else if (ps->top.dir_a == 1)
	{
		while (++j < ps->top.mag_a)
			ft_putstr_fd("ra\n", 2);
	}
	if (ps->top.dir_b == 0)
	{
		while (++j < ps->top.mag_b)
			ft_putstr_fd("rrb\n", 2);
	}
	else if (ps->top.dir_b == 1)
	{
		while (++j < ps->top.mag_b)
			ft_putstr_fd("rb\n", 2);
	}
}

void	push_creator(t_ps *ps, int ac, char **av)
{
	int i;
	int j;
	int k;

	i = ac - ps->trig;
	while (i >= 0)
	{
		push(ps->a, ft_atoi(av[i]));
		i--;
	}
//	fprintf(stderr, "########%i\n",ps->a->top);
	while (check_sort_int(ps) == 1)
	{
		j = -1;
		k = -1;
		valid_rot(ps);
		make_play(j, k, ps);
		print_play(j, k, ps);
		ft_pb(ps);
		ft_putstr_fd("pb\n", 2);
//		display_stack(ps->a, ps->b);
	}
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
	push_creator(ps, ac, av);
	valid_rot(ps);
	return 0;
}
