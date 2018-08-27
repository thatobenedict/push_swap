/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:08:31 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/27 08:50:50 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
			{
				ft_putstr_fd("Error\n", 2);
				exit (-1);
			}
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

	i = 0;
	j = 0;
	trig = ps->trig;
	if (trig == 2)
		trig = 0;
	while (numbers[i + trig] != 0)
	{
		j = 0;
		while (numbers[i + trig][j] != '\0')
		{
			if ((numbers[i + trig][j] == '+' ||
					   	numbers[i + trig][j] == '-'))
			{
				j++;
				if (ft_isdigit(numbers[i + trig][j]) == 0)
				{
					ft_putstr_fd("Error\n", 2);
					exit (-1);
				}
			}
			else
			{
				if (ft_isdigit(numbers[i + trig][j]) == 0)
				{
					ft_putstr_fd("Error\n", 2);
					exit (-1);
				}
				j++;
			}
		}
		i++;
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
		{
			ft_putstr_fd("Error\n", 2);
			exit (-1);
		}
		i++;
	}
}

/*
 ** Errors include for example: 			
 ** some arguments are not integers, 				
 ** some arguments are bigger than an integer,		
 ** there are duplicates, 							###DONE
 ** an instruction don’t exist and/or is			
 ** incorrectly formatted.							
 */
