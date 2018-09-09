/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:44:05 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/09 12:19:12 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

/*
 **void	make_play(int j, int k, t_ps *ps)
 **{
 **	if (ps->top.dir_a == 1 && ps->top.dir_b == 1)
 **	{
 **		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
 **			ft_rr(ps);
 **	}
 **	if (ps->top.dir_a == 0 && ps->top.dir_b == 0)
 **	{
 **		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
 **			ft_rrr(ps);
 **	}
 **	if (ps->top.dir_a == 0)
 **	{
 **		while (++j < ps->top.mag_a)
 **			ft_rra(ps);
 **	}
 **	else if (ps->top.dir_a == 1)
 **	{
 **		while (++j < ps->top.mag_a)
 **			ft_ra(ps);
 **	}
 **	if (ps->top.dir_b == 0)
 **	{
 **		while (++j < ps->top.mag_b)
 **			ft_rrb(ps);
 **	}
 **	else if (ps->top.dir_b == 1)
 **	{
 **		while (++j < ps->top.mag_b)
 **			ft_rb(ps);
 **	}
 **}
 **
 **void	print_play(int j, int k, t_ps *ps)
 **{
 **	if (ps->top.dir_a == 1 && ps->top.dir_b == 1)
 **	{
 **		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
 **			ft_putstr_fd("rr\n", 2);
 **	}
 **	if (ps->top.dir_a == 0 && ps->top.dir_b == 0)
 **	{
 **		while (++j < ps->top.mag_a && ++k < ps->top.mag_b)
 **			ft_putstr_fd("rrr\n", 2);
 **	}
 **	if (ps->top.dir_a == 0)
 **	{
 **		while (++j < ps->top.mag_a)
 **			ft_putstr_fd("rra\n", 2);
 **	}
 **	else if (ps->top.dir_a == 1)
 **	{
 **		while (++j < ps->top.mag_a)
 **			ft_putstr_fd("ra\n", 2);
 **	}
 **	if (ps->top.dir_b == 0)
 **	{
 **		while (++j < ps->top.mag_b)
 **			ft_putstr_fd("rrb\n", 2);
 **	}
 **	else if (ps->top.dir_b == 1)
 **	{
 **		while (++j < ps->top.mag_b)
 **			ft_putstr_fd("rb\n", 2);
 **	}
 **}
 **
 **void	push_creator(t_ps *ps, int ac, char **av)
 **{
**	int i;
**	int j;
**	int k;
**
**	i = ac - ps->trig;
**	while (i >= 0)
	**	{
		**		push(ps->a, ft_atoi(av[i]));
		**		i--;
		**	}
		**	ft_pb(ps);
		**	ft_putstr_fd("pb\n", 2);
		**	ft_pb(ps);
		**	ft_putstr_fd("pb\n", 2);
		**	display_stack(ps->a, ps->b);
**	while (check_sort_int(ps) == 1)
	**	{
		**		j = -1;
		**		k = -1;
		**		ps->top.dir_a = 0;
		**		ps->top.dir_b = 0;
		**		ps->top.mag_a = 0;
		**		ps->top.mag_b = 0;
		**		display_stack(ps->a, ps->b);
		**		valid_rot(ps);
		**		make_play(j, k, ps);
		**		print_play(j, k, ps);
		**		ft_pb(ps);
		**		ft_putstr_fd("pb\n", 2);
		**		display_stack(ps->a, ps->b);
		**	}
		**}
		*/

void	dynamic_sort(t_ps *ps)
{
	//	ft_putnbr(ps->score.mag);
	//	ft_putchar('\n');
	//		ft_putnbr(ps->score.mag_a);
	//		ft_putchar('\n');
	//		ft_putnbr(ps->score.mag_b);
	//		ft_putchar('\n');
	//	ft_putnbr()

	do_pb(ps);
	do_pb(ps);

	hard_sort2_b(ps);
	ft_putstr("here 1\n");         //go together
	display_stack(ps->a, ps->b);   // go together
	int i = ps->a->top;
	while (i >= 0)
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
		while (ps->score.mag_a > 0)
		{
			if (ps->score.dir == 0)
				do_ra(ps);
			else
				do_rra(ps);
			ps->score.mag_a--;
		}
		while (ps->score.mag_b > 0)
		{
			if (ps->score.dir == 0)
				do_rb(ps);
			else
				do_rrb(ps);
			ps->score.mag_b--;
		}
		do_pb(ps);
		i--;
	}
	b_max_to_top(ps);
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
