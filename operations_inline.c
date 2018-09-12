/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_inline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:58:45 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/12 11:02:47 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	apply(t_ps *ps)
{
	while (get_next_line(0, &(ps->gnl.line)) > 0)
	{
		if (ft_strcmp(ps->gnl.line, "sa") == 0)
			ft_sa(ps);
		else if (ft_strcmp(ps->gnl.line, "sb") == 0)
			ft_sb(ps);
		else if (ft_strcmp(ps->gnl.line, "ss") == 0)
			ft_ss(ps);
		else if (ft_strcmp(ps->gnl.line, "pa") == 0)
			ft_pa(ps);
		else if (ft_strcmp(ps->gnl.line, "pb") == 0)
			ft_pb(ps);
		else if (ft_strcmp(ps->gnl.line, "ra") == 0)
			ft_ra(ps);
		else if (ft_strcmp(ps->gnl.line, "rb") == 0)
			ft_rb(ps);
		else if (ft_strcmp(ps->gnl.line, "check") == 0)
			break ;
		else
			apply_ext(ps);
		free(ps->gnl.line);
	}
}

void	apply_ext(t_ps *ps)
{
	if (ft_strcmp(ps->gnl.line, "rr") == 0)
		ft_rr(ps);
	else if (ft_strcmp(ps->gnl.line, "rra") == 0)
		ft_rra(ps);
	else if (ft_strcmp(ps->gnl.line, "rrb") == 0)
		ft_rrb(ps);
	else if (ft_strcmp(ps->gnl.line, "rrr") == 0)
		ft_rrr(ps);
	else if (ft_strcmp(ps->gnl.line, "display") == 0)
		display_stack(ps->a, ps->b);
	else
		message(-2);
	//relieve_yourself(ps);i
}

void	check_sort(t_ps *ps)
{
	int i;

	if (ps->b->top == -1)
	{
		i = 0;
		while (i < ps->a->top)
		{
			if (ps->a->array[i] > ps->a->array[i + 1])
				i++;
			else
			{
				ft_putstr_fd(UNSORTED, 2);
				exit(relieve_yourself(ps));
			}
		}
		ft_putstr_fd(SORTED, 2);
		exit(relieve_yourself(ps));
	}
	ft_putstr_fd(UNSORTED, 2);
	exit(relieve_yourself(ps));
}

int		check_sort_int(t_ps *ps)
{
	int i;

	if (ps->b->top == -1)
	{
		i = 0;
		while (i < ps->a->top)
		{
			if (ps->a->array[i] > ps->a->array[i + 1])
				i++;
			else
				return (1);
		}
		return (0);
	}
	return (1);
}

int		check_sort_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] > stack->array[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
