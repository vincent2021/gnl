/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:23:55 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/22 19:58:28 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl				*ft_get_mem(int fd, t_gnl *mem)
{
	t_gnl			*tmp;

	tmp = mem;
	while (tmp)
	{
		if(fd == tmp->fd)
			return (tmp);
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
	return (mem);
}

t_gnl						*ft_lst_new(int fd)
{
	t_gnl					*new;

	if (!(new = malloc(sizeof(t_gnl))))
			return (NULL);
	new->fd = fd;
	new->content_size = 0;
	new->content = NULL;
	new->next = NULL;
	return (new);
}

char				*ft_read(t_gnl *mem, int fd)
{
	size_t			i;
	char			*buf;
	size_t			c_read;
	char			*str;

	buf = malloc(BUFF_SIZE + 1);
	str = mem->content;
	if (str)
	{
		i = 0;
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			str = ft_strsub(str, 0, i);
			mem->content  = mem->content + i;
			return (str);
		}
	}
	while ((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[c_read] = '\0';
		while (buf[i] != '\n' && buf[i])
			i++;
		ft_strncat(str, buf, i);
		if (buf[i] == '\n' && i < BUFF_SIZE)
		{
			mem->content = malloc(sizeof(char) * BUFF_SIZE - i);
			ft_strncpy(mem->content, buf + i + 1, BUFF_SIZE - i);
			free(buf);
			return (str);
		}
	}
	return (0);
}

int					get_next_line_new(const int fd, char **line)
{
	static t_gnl	*mem;
	t_gnl			*tmp;
	char			*str;

	if (!mem)
		mem = ft_lst_new(fd);
	if (!mem || line == NULL || fd < 0)
		return (-1);
	tmp = ft_get_mem(fd, mem);
	str = ft_read(tmp, fd);
	if (ft_strlen(str) > 0)
	{
		*line = str;
		return (1);
	}
	else
	{
		free(str);
		return (0);
	}
}
