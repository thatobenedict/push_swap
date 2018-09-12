/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:44:05 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/11 18:20:02 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	dynamic_sort_helper(t_ps *ps)
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
	do_pb(ps); // based on git changes 
}

void	dynamic_sort(t_ps *ps)
{
	do_pb(ps);
	do_pb(ps);
	hard_sort2_b(ps);
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
		//here1
		while (ps->score.mag_a > 0)
		{
			if (ps->score.dir_a == 0)
				do_ra(ps);
			else
				do_rra(ps);
			ps->score.mag_a--;
			display_stack(ps->a, ps->b);   // delete me
		}
		while (ps->score.mag_b > 0)
		{
			if (ps->score.dir_b == 0)
				do_rb(ps);
			else
				do_rrb(ps);
			ps->score.mag_b--;
			display_stack(ps->a, ps->b);   // delete me
		}
		do_pb(ps);
		display_stack(ps->a, ps->b);   // delete me
		ps->score.top = 1000;
		ps->score.mag_a = 0;
		ps->score.mag_b = 0;
		ps->score.dir_a = 0;
		ps->score.dir_b = 0;
		ps->score.mag = 0;
		ps->score.dir = 0;
		//here2
		//	dynamic_sort_helper(ps);
		//	push_b_reset_score(ps);
	}
	b_max_to_top(ps);
	while (ps->b->top >= 0)
		do_pa(ps);
}

void	push_create(t_ps *ps)
{	ft_putnbr(ps->ac);
ft_putchar('\n');

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
	ft_putnbr(ps->ac);
ft_putchar('\n');
	push_create(ps);
	ps->a = new_stack(ac - 1);
	ps->b = new_stack(ac - 1);
	i = ac - ps->trig + 1;
	while (--i >= 0)
		push(ps->a, ft_atoi(av[i]));
	if (check_sort_int(ps) == 0)
		return (0);
	else if (ps->ac == 3)
		hard_sort2(ps);
	else if (ps->ac == 4)
		hard_sort3(ps);
	else if (ps->ac == 5 || ps->ac == 6)
		hard_sort4_5(ps);
	else
	{
		dynamic_sort(ps);
		display_stack(ps->a, ps->b);   // delete me
	}
	return (0);
}
