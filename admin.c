/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:08:31 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/23 18:54:12 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_duplicates(char **numbers, int count, int trig)
{
	int i;
	int j;
	int end;

	i = 0;
	j = 0;
	end = count - (trig - 1) - 1;
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

void	is_int(char **numbers, int count, int trig)
{
	int i;
	int j;
	int end;

	i = 0;
	j = 0;
	end = count - (trig - 1) - 1;
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


/*
 ** Errors include for example: 			
 ** some arguments are not integers, 			
 ** some arguments are bigger than an integer,		
 ** there are duplicates, 				###DONE
 ** an instruction don’t exist and/or is		
 ** incorrectly formatted.				
 */
