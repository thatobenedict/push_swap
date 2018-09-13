/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:08:31 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/13 17:56:04 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_initial(t_ps *ps)
{
	ps->trig = 0;
	ps->gnl.line = NULL;
//	ps->top.dir_a = 0;
//	ps->top.dir_b = 0;
//	ps->top.dir = 0;
}

void	ft_duplicates(t_ps *ps, char **numbers, int count)
{
	int i;
	int j;
	int end;

	if (ps->trig == 1)
		i = 1;
	else
		i = 0;
	j = 0;
	end = count;
	while (i < end)
	{
		j = i + 1;
		while (j < end)
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				message(-1);
			j++;
		}
		i++;
	}
}

void	is_digits(char **numbers, t_ps *ps)
{
	int i;
	int j;
	int trig;

	i = -1;
	trig = ps->trig;
	if (trig == 2)
		trig = 0;
	while (numbers[++i + trig] != 0)
	{
		j = -1;
		while (numbers[i + trig][++j] != '\0')
		{
			if ((numbers[i + trig][j] == '+' || numbers[i + trig][j] == '-'))
			{
				if (ft_isdigit(numbers[i + trig][++j]) == 0)
					message(-1);
			}
			else
			{
				if (ft_isdigit(numbers[i + trig][j]) == 0)
					message(-1);
			}
		}
	}
}

void	is_int(char **numbers, t_ps *ps)
{
	int i;
	int trig;

	i = 0;
	trig = ps->trig;
	if (trig == 2)
		trig = 0;
	while (numbers[i + trig] != 0)
	{
		if (ft_atol(numbers[i + trig]) < -2147483648 ||
				ft_atol(numbers[i + trig]) > 2147483647)
			message(-1);
		i++;
	}
}

void	err_admin(int ac, char **av, t_ps *ps)
{
	if ((ps->trig == 2 && ac == 0) || (ps->trig == 1 && ac == 1))
	{
		//message(-2);
		exit(-1);
	}
	ft_duplicates(ps, av, ac);
	is_digits(av, ps);
	is_int(av, ps);
}
