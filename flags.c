/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:39:10 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/30 11:41:34 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//###HOLDING ON TO THIS 
//###MAKE IT FUNCTIONAL FOR LATER

if (ft_strcmp(av[1],"-v") == 0 || ft_strcmp(av[2], "-v") == 0 ||
				ft_strcmp(av[1],"-c") == 0 || ft_strcmp(av[2], "-c") == 0)
	{
		if (ft_strcmp(av[1],"-v") == 0 || ft_strcmp(av[2], "-v") == 0)
			ps->flag.x = 0;
		if (ft_strcmp(av[1],"-c") == 0 || ft_strcmp(av[2], "-c") == 0)
			ps->flag.y = 0;
	}
