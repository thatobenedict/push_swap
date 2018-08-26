/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:08:31 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/26 18:18:23 by tbenedic         ###   ########.fr       */
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
				ft_putstr_fd("Error0\n", 2);
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

	i = 0;
	j = 0;
	if (ps->admin.in_type == 2)
		ps->admin.in_type = 0;
	while (numbers[i + ps->admin.in_type] != 0)
	{
		j = 0;
		while (numbers[i + ps->admin.in_type][j] != '\0')
		{
			if ((numbers[i + ps->admin.in_type][j] == '+' ||
					   	numbers[i + ps->admin.in_type][j] == '-'))
			{
				j++;
				if (ft_isdigit(numbers[i + ps->admin.in_type][j]) == 0)
				{
					ft_putstr_fd("Error1\n", 2);
					exit (-1);
				}
			}
			else
			{
				if (ft_isdigit(numbers[i + ps->admin.in_type][j]) == 0)
				{
					ft_putnbr_fd(numbers[i + ps->admin.in_type][j], 2);
					ft_putchar_fd('\n',2);
					ft_putstr_fd("Error2\n", 2);
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

	i = 0;
	if (ps->admin.in_type == 2)
		ps->admin.in_type = 0;
	while (numbers[i + ps->admin.in_type] != 0)
	{
		if (ft_atol(numbers[i + ps->admin.in_type]) < -2147483648 ||
				ft_atol(numbers[i + ps->admin.in_type]) > 2147483647)
		{
			ft_putstr_fd("Error3\n", 2);
			exit (-1);
		}
		i++;
	}
}

void	error_handle(char **numbers, int count, t_ps *ps)
{
	if (count == 2)
	{
		ps->admin.in_type = 2;
		count = ft_white_word_count(numbers[1]) + 1;
		numbers = ft_strsplit(numbers[1], ' ');
	}
	else
		ps->admin.in_type = 1;
	ft_duplicates(numbers, count);
	is_digits(numbers, ps);
	is_int(numbers, ps);
}
/*
 ** Errors include for example: 			
 ** some arguments are not integers, 				
 ** some arguments are bigger than an integer,		
 ** there are duplicates, 							###DONE
 ** an instruction don’t exist and/or is			
 ** incorrectly formatted.							
 */
