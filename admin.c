/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:08:31 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 18:36:39 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_initial(t_ps *ps)
{
	ps->trig = 0;
	ps->gnl.line = NULL;
}

void	ft_duplicates(char **numbers, int count)
{
	int i;
	int j;
	int end;

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
