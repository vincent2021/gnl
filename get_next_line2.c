/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/17 18:13:50 by vimucchi         ###   ########.fr       */
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
	
	if (!(buf = malloc(sizeof(char)*(BUFF_SIZE+1))));
		return (-1);
	if (fd = 0 || line = NULL || read(fd, buf, BUFF_SIZE) == -1)
		return (-1);
	
	c_line = 0;
	if((c_read = read(fd, buf, BUFF_SIZE)) != 0)
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
