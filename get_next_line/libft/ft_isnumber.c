/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:19:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 18:43:17 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isnumber(char *str)
{
	int i;

	i = 0;
	while (str)
	{
		if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
			i++;
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}
