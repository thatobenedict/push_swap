/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:08:31 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/24 17:20:39 by tbenedic         ###   ########.fr       */
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

void	is_digits(char **numbers, int trig)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (trig == 2)
		trig = 0;
	while (numbers[i + trig] != 0)
	{
		j = 0;
		while (numbers[i + trig][j] != '\0')
		{
			if ((numbers[i + trig][j] == '+' || numbers[i + trig][j] == '-'))
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

void	is_int(char **numbers, int trig)
{
	int i;

	i = 0;
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

void	error_handle(char **numbers, int count, t_admin admin)
{
	if (count == 2)
	{
		trig = 2;
		count = ft_white_word_count(numbers[1]) + 1;
		numbers = ft_strsplit(numbers[1], ' ');
		error_handle(numbers, f->in_type, count - 1);
	}
	else
	{
		f->in_type = 1;
		error_handle(av, trig, count - 1);
	}



	ft_duplicates(numbers, count);
	is_digits(numbers, f->in_type);
	is_int(numbers, f->in_type);
}
/*
 ** Errors include for example: 			
 ** some arguments are not integers, 				
 ** some arguments are bigger than an integer,		
 ** there are duplicates, 							###DONE
 ** an instruction don’t exist and/or is			
 ** incorrectly formatted.							
 */
