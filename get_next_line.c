/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/18 17:22:40 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static t_list	gnl;
	char			*buf;
	char			*str;
	int				i;
	int				c_read;
	t_list			tmp;

	tmp = gnl;
	str = ft_strnew(1000);
	*line = str;	
	if (!(buf = malloc(sizeof(char)*(BUFF_SIZE+1))))
		return (-1);
	if (fd == 0 || line == NULL || read(fd, buf, BUFF_SIZE) == -1)
		return (-1);
	while((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[BUFF_SIZE + 1] = '\0';
		ft_putendl(buf);
		while (buf[i] != '\n' && buf[i])			
			i++;
		ft_strncat(str, buf, i);
		if (buf[i] == '\n')
			return (1);
	}
	return (0);
}
