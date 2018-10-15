/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/15 20:05:46 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char	*buf;
	int		i;
	int		j;
	int		c_read;
	int		c_line;

	buf = malloc(sizeof(char)*(BUF_SIZE+1));
	c_line = 0;
	line[c_line] = malloc(1024);
	while((c_read = read(fd, buf, BUF_SIZE)) != 0)
	{
		i = 0;
		while (buf[i] != '\n' && i < c_read)
			i++;
		ft_strncat(line[c_line], buf, i);
		if (buf[i] == '\n')
		{
			c_line++;
			line[c_line] = malloc(1024);
		}
		if (i < c_read)
			ft_strncat(line[c_line], buf + i + 1, c_read - i - 1);
	}
	j = 0;
	ft_putstr("Line: \n");
	while(j < c_line)
	{
		ft_putstr(line[j]);
		ft_putchar('\n');
		j++;
	}
	return(0);
}
