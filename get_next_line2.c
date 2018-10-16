/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/16 19:41:04 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(const int fd, char **line)
{
	char	*buf;
	char	*str;
	int		i;
	int		c_read;
	int		c_line;

	buf = malloc(sizeof(char)*(BUF_SIZE+1));
	c_line = 0;
	if((c_read = read(fd, buf, BUF_SIZE)) != 0)
	{
		i = 0;
		while (buf[i] != '\n' && buf[i])
			i++;
		str = ft_strnew(i + 1);
		ft_strncat(str, buf, i);
	}
	else
		return (0);
	line = &str;
	ft_putstr("Get line Function:\n");
	ft_putstr(*line);
	return (1);
}
