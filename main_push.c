/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:44:05 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/16 10:30:35 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_zero2(t_ps *ps)
{
	ps->score.top = 1000;
	ps->score.mag_a = 0;
	ps->score.mag_b = 0;
	ps->score.dir_a = 0;
	ps->score.dir_b = 0;
	ps->score.mag = 0;
	ps->score.dir = 0;
}

void	while_ab(t_ps *ps)
{
	while (ps->score.mag_a > 0)
	{
		if (ps->score.dir_a == 0)
			do_ra(ps);
		else
			do_rra(ps);
		ps->score.mag_a--;
	}
	while (ps->score.mag_b > 0)
	{
		if (ps->score.dir_b == 0)
			do_rb(ps);
		else
			do_rrb(ps);
		ps->score.mag_b--;
	}
}

void	dynamic_sort(t_ps *ps)
{
	int turn;

	turn = -1;
	do_pb(ps);
	do_pb(ps);
	while (ps->a->top >= 0)
	{
		sort_engine(ps);
		while (ps->score.mag > 0)
		{
			if (ps->score.dir == 0)
				do_rr(ps);
			else
				do_rrr(ps);
			ps->score.mag--;
		}
		while_ab(ps);
		if (++turn == 0)
			hard_sort2_b(ps);
		do_pb(ps);
		set_zero2(ps);
	}
	b_max_to_top(ps);
	while (ps->b->top >= 0)
		do_pa(ps);
}

void	push_create(t_ps *ps)
{
	if (ps->ac == 2)
	{
		ps->trig = 2;
		ps->ac = ft_white_word_count(ps->av[1]) + 1;
		ps->av = ft_strsplit(ps->av[1], ' ');
		err_admin(ps->ac - 1, ps->av, ps);
	}
	else
	{
		ps->trig = 1;
		err_admin(ps->ac, ps->av, ps);
	}
}

int		main(int ac, char **av)
{
	t_ps	*ps;
	int		i;

	ps = ft_memalloc(sizeof(t_ps));
	ft_initial(ps);
	ps->ac = ac;
	ps->av = av;
	push_create(ps);
	ps->a = new_stack(ps->ac - 1);
	ps->b = new_stack(ps->ac - 1);
	i = ps->ac - ps->trig + 1;
	while (--i >= 0)
		push(ps->a, ft_atoi(ps->av[i]));
	if (check_sort_int(ps) == 0)
		return (0);
	else if (ps->ac == 3)
		hard_sort2(ps);
	else if (ps->ac == 4)
		hard_sort3(ps);
	else if (ps->ac == 5 || ps->ac == 6)
		hard_sort4_5(ps);
	else
		dynamic_sort(ps);
	exit(relieve_yourself(ps));
	return (0);
}
