/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:52:10 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/16 11:10:08 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		new_line_ind(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

static char		*ft_remainder(char *line)
{
	char	*new;

	new = ft_strchr(line, '\n');
	if ((new != NULL))
	{
		new++;
		new = ft_strdup(new);
	}
	return (new);
}

void			swapnfree(char **var, char *new_val)
{
	char	*tmp;

	free(*var);
	tmp = new_val;
	*var = tmp;
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*keep[9999];
	int			buffout;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (READ_ERROR);
	if (keep[fd] == NULL)
		keep[fd] = ft_strdup("");
	while ((buffout = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[buffout] = '\0';
		swapnfree(&keep[fd], ft_strjoin(keep[fd], buf));
		if (ft_contain_char(keep[fd], '\n'))
			break ;
	}
	if (*keep[fd] == 0 && buffout == 0)
	{
		free(keep[fd]);
		keep[fd] = NULL;
		return (READ_COMPLETE);
	}
	swapnfree(line, ft_strndup(keep[fd], new_line_ind(keep[fd])));
	swapnfree(&keep[fd], ft_remainder(keep[fd]));
	return (READ_SUCCESS);
}
