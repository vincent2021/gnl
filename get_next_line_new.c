/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:23:55 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/21 18:50:19 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_get_mem(int fd, t_gnl *mem)
{
	t_gnl			*tmp;
	size_t			i;

	tmp = mem;
	while (tmp)
	{
		if(fd == tmp->fd)
			return (tmp->content);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_gnl));
	if (tmp)
	{
		tmp->fd = fd;
		tmp->content = ft_strnew(1);
		tmp->next = mem;
	}
	mem = tmp;
	return (mem->content);
}

int					get_next_line_new(const int fd, char **line)
{
	size_t			i;
	char			*buf;
	size_t			c_read;
	static t_gnl	*mem;
	char			*str;

	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!mem)
		mem = malloc(sizeof(t_gnl));
	if (!buf || !mem || line == NULL || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	str = ft_get_mem(fd, mem);
	if (str)
	{
		i = 0;
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, 0, i);
			str = str + i;
			return (1);
		}
	}
	while ((c_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		buf[c_read] = '\0';
		while (buf[i] != '\n' && buf[i])
			i++;
		return (1);
	}
return (0);
}
