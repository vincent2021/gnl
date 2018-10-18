/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/17 14:54:32 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(const int fd, char **line)
{
	char	*buf;
	char	*str;
	int		i;
	int		flag_nl;
	int		c_read;

	buf = malloc(sizeof(char)*(BUF_SIZE+1));
	flag_nl = 0;
	if((c_read = read(fd, buf, BUF_SIZE)) != 0 && flag_nl == 0)
	{
		i = 0;
		while (buf[i] != '\n' && buf[i])
			i++;
		str = ft_strnew(i + 1);
		ft_strncat(str, buf, i);
		if (buf[i] == '\n')
			flag_nl = 1;
	}
	*line = str;
	free(buf);
	return (1);
}
