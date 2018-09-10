/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:40:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/10 18:50:23 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define SORTED "OK\n"
# define UNSORTED "KO\n"
# define ERROR "Error\n"
# define MIN_INT (-MAX_INT - 1)
# define MAX_INT 2147483647
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

typedef struct	s_cord
{
	int			x;
	int			y;
}				t_cord;

typedef struct	s_gnl
{
	int			fd;
	char		*line;
}				t_gnl;

typedef struct	s_stack
{
	int			top;
	int			size;
	int			*array;
	int			mid;
}				t_stack;

typedef struct	s_score
{
	int			mag_a;
	int			mag_b;
	int			dir_a;
	int			dir_b;
	int			top;
	int			mag;
	int			dir;
}				t_score;

typedef struct	s_ps
{
	t_stack		*a;
	t_stack		*b;
	int			trig;
	t_gnl		gnl;
	t_score		score;
	int			hard_trig;
	int			ac;
	char		**av;
}				t_ps;
/*
** ======================================================== admin.c
*/
void			ft_initial(t_ps	*ps);
void			ft_duplicates(t_ps *ps, char **numbers, int count);
void			is_digits(char **numbers, t_ps *ps);
void			is_int(char **numbers, t_ps *ps);
void			err_admin(int ac, char **av, t_ps *ps);
/*
** ======================================================== stack_basics.c
*/
t_stack			*new_stack(size_t size);
int				stack_state(t_stack *ps);
void			push(t_stack *ps, int integer);
int				pop(t_stack *ps);
int				ret_index(int value, t_stack *array);
/*
** ======================================================== display.c
*/
void			display_stack(t_stack *a, t_stack *b);
void			message(int signal);
/*
** ======================================================== operations1.c
*/
void			ft_sa(t_ps *stack);
void			ft_sb(t_ps *stack);
void			ft_ss(t_ps *stack);
void			ft_pa(t_ps *stack);
void			ft_pb(t_ps *stack);
/*
** ======================================================== operations2.c
*/
void			ft_ra(t_ps *stack);
void			ft_rb(t_ps *stack);
void			ft_rra(t_ps *stack);
void			ft_rrb(t_ps *stack);
/*
** ======================================================== operations3.c
*/
void			ft_rr(t_ps *stack);
void			ft_rrr(t_ps *stack);
/*
** ======================================================== operations_inline.c
*/
void			apply(t_ps *ps);
void			apply_ext(t_ps *ps);
void			check_sort(t_ps *stack);
int				check_sort_int(t_ps *ps);
int				check_sort_stack(t_stack *stack);
/*
** ======================================================== algo.c
*/
int				between(int a, int z, int x);
void			score_gen(int i_a, int i_b, t_ps *ps);
int				who_min(t_stack *array);
int				who_max(t_stack *array);
int				check_cycle(t_stack *stack);
void			valid_rot(t_ps *ps);
/*
** ======================================================== algo2.c
*/
void			rotates(t_ps *ps);
void			hard_sort2(t_ps *pa);
void			hard_sort3(t_ps *ps);
void			hard_sort4_5(t_ps *ps);
/*
** ======================================================== algo3.c
*/
void			hard_sort2_b(t_ps *ps);
int             ab_score(int i, t_stack *stack);
int             rot_score(t_stack *stack);
int             real_rot(int a, int b);
int             is_between(int a, int b, int c);
int             is_valid(int i, int j, t_ps *ps);
void			store_top(int a, int b, t_ps *ps);
void			b_max_to_top(t_ps *ps);
void			sort_engine(t_ps *ps);
/*
** ======================================================== do_ps1.c
*/
void			do_sa(t_ps *stack);
void			do_sb(t_ps *stack);
void			do_ss(t_ps *stack);
void			do_pa(t_ps *stack);
void			do_pb(t_ps *stack);
/*
** ======================================================== do_ps2.c
*/
void			do_ra(t_ps *stack);
void			do_rb(t_ps *stack);
void			do_rra(t_ps *stack);
void			do_rrb(t_ps *stack);
/*
** ======================================================== do_ps3.c
*/
void			do_rr(t_ps *stack);
void			do_rrr(t_ps *stack);
#endif
