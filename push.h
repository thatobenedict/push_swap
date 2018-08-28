/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:40:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 17:57:28 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define SORTED "OK\n"
# define UNSORTED "KO\n"
# define ERROR "Error\n"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

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

}				t_stack;

typedef struct	s_ps
{
	t_stack		*a;
	t_stack		*b;
	int			trig;
	t_gnl		gnl;
}				t_ps;
/*
** Prototypes for main.c
*/

/*
** Prototypes for stack_basics.c
*/
t_stack		*new_stack(size_t size);
int			stack_state(t_stack *ps);
void		push(t_stack *ps, int integer);
int			pop(t_stack *ps);
void		display_stack(t_stack *a, t_stack *b);
void		ft_initial(t_ps  *ps);
void		ft_duplicates(char **numbers, int count);
void		is_digits(char **numbers, t_ps *ps);
void		is_int(char **numbers, t_ps *ps);
void		apply(t_ps *ps);
void		check_sort(t_ps *stack);
void		ft_sa(t_ps *stack);
void		ft_sb(t_ps *stack);
void		ft_ss(t_ps *stack);
void		ft_pa(t_ps *stack);
void		ft_pb(t_ps *stack);
void		ft_ra(t_ps *stack);
void		ft_rb(t_ps *stack);
void		ft_rr(t_ps *stack);
void		ft_rra(t_ps *stack);
void		ft_rrb(t_ps *stack);
void		ft_rrr(t_ps *stack);

#endif
