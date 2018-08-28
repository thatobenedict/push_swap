/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:13:42 by tbenedic          #+#    #+#             */
/*   Updated: 2018/08/28 16:00:43 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*new;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * (size + 1));
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[size] = '\0';
	return (new);
}
