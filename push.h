/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:40:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/26 18:18:29 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define SORTED "OK\n"
# define UNSORTED "KO\n"
# define ERROR "Error\n"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>

typedef struct	s_stack
{
	int			top;
	int			size;
	int			*array;
}				t_stack;

typedef struct s_admin
{
	int			in_type;
}				t_admin;

typedef	struct	s_ps
{
	t_stack		a;
	t_stack		b;
	t_admin		admin;
}				t_ps;
/*
** Prototypes for stack_basics.c
*/
t_stack		new_stack(size_t size);
int			stack_state(t_stack *ps);
void		push(t_stack *ps, int integer);
int			pop(t_stack *ps);
void		display_stack(t_ps *ps);
void		ft_duplicates(char **numbers, int count);
void		is_digits(char **numbers, t_ps *ps);
void		is_int(char **numbers, t_ps *ps);
void		error_handle(char **numbers, int count, t_ps *ps);
/*
** Prototypes for stack_basics.c
*/

#endif
