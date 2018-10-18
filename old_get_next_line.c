/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/18 16:00:41 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	old_get_next_line(const int fd, char **line)

{
	char	*buf;
	int		i;
	int		j;
	int		c_read;
	int		c_scan;
	int		c_line;

	buf = malloc(sizeof(char)*(BUFF_SIZE+1));
	c_line = 0;
	line[c_line] = malloc(1024);
	while((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		c_scan = 0;
		while(c_scan < c_read)
		{
			i = 0;
			while (buf[i] != '\n' && buf[i])
			{
				i++;
				c_scan++;
			}
			ft_strncat(line[c_line], buf, i);
			if (buf[i] == '\n')
			{
				c_line++;
				line[c_line] = malloc(1024);
				c_scan++;
				i++;
			}
			buf = buf + i;
		}
	}
	j = 0;
	ft_putstr("GNL Function:\n");
	while(j < c_line)
	{
		ft_putstr(line[j]);
		ft_putchar('\n');
		j++;
	}
	return(0);
}
