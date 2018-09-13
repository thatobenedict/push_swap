/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:22:25 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/13 13:18:00 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_absdiff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int		between(int a, int z, int x)
{
	if (a < z)
	{
		if (x > a && x < z)
			return (0);
		else
			return (1);
	}
	else
	{
		if (x > z && x < a)
			return (0);
		else
			return (1);
	}
}

int		who_min(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->array[0];
	while (i <= array->top)
	{
		if (j > array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}

int		who_max(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->array[0];
	while (i <= array->top)
	{
		if (j < array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}
