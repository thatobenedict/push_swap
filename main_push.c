/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:44:05 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/10 18:49:40 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	dynamic_sort(t_ps *ps)
{
	do_pb(ps);
	do_pb(ps);

	hard_sort2_b(ps);
	display_stack(ps->a, ps->b);   // delete me
	while (ps->a->top >= 0)
	{
		sort_engine(ps);
		ft_putstr("ps->score.top   :");
		ft_putnbr(ps->score.top);
		ft_putchar('\n');
		ft_putstr("ps->score.mag_a :");
		ft_putnbr(ps->score.mag_a);
		ft_putchar('\n');
		ft_putstr("ps->score.mag_b :");
		ft_putnbr(ps->score.mag_b);
		ft_putchar('\n');
		ft_putstr("ps->score.dir_a :");
		ft_putnbr(ps->score.dir_a);
		ft_putchar('\n');
		ft_putstr("ps->score.dir_b :");
		ft_putnbr(ps->score.dir_b);
		ft_putchar('\n');
		ft_putstr("ps->score.mag   :");
		ft_putnbr(ps->score.mag);
		ft_putchar('\n');
		ft_putstr("ps->score.dir   :");
		ft_putnbr(ps->score.dir);
		ft_putchar('\n');

		while (ps->score.mag > 0)
		{
			if (ps->score.dir == 0)
				do_rr(ps);
			else
				do_rrr(ps);
			ps->score.mag--;
			display_stack(ps->a, ps->b);   // delete me
		}
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
	
		ps->score.top = 10000;
	ps->score.mag_a = 0;
	ps->score.mag_b = 0;
	ps->score.dir_a = 0;
	ps->score.dir_b = 0;
	ps->score.mag = 0;
	ps->score.dir = 0;
	}
	b_max_to_top(ps); //								 $$$ WORKING LIKE A GEM
	display_stack(ps->a, ps->b);   // go together
	while (ps->b->top >= 0)
		do_pa(ps);
	display_stack(ps->a, ps->b);   // go together
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
		dynamic_sort(ps);
	return (0);
}
