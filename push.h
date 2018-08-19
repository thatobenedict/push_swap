/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:40:13 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/19 18:21:30 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define SORTED "OK\n"
# define UNSORTED "KO\n"
# define ERROR "Error\n"
# include "get_next_line/get_next_line.h"

typedef struct	s_stack
{
	int			top;
	size_t		size;
	int			*array;
}				t_stack;

typedef struct	s_ps
{
	t_stack		*stack;
}				t_ps;
#endif
