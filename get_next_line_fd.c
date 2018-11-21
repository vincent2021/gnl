/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:22:15 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/21 16:26:39 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl						*ft_lst_new(t_gnl *mem, size_t fd)
{
	t_gnl					*new;

	if (!(new = malloc(sizeof(t_gnl))))
			return (NULL);
	new->fd = fd;
	new->content_size = 0;
	new->content = NULL;
	new->next = mem;
	return (new);
}

t_gnl			*ft_lst_mgmt(t_gnl *mem, size_t fd)
{
	t_gnl		*tmp;

	tmp = mem;
	while (tmp)
	{
		if ((size_t)fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lst_new(mem, fd);
	return (tmp);
}

int					get_next_line_fd(const int fd, char **line)
{
	char			*buf;
	char			*str;
	char			*remain;
	int				i;
	int				c_read;
	static t_gnl	*mem;
	t_gnl			*tmp;

	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (line == NULL || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	if (!mem)
	{
		mem = malloc(sizeof(t_gnl));
		mem->content_size = 0;
		mem->content = NULL;
		mem->fd = fd;
		mem->next = NULL;
	}
	tmp = ft_lst_mgmt(mem, fd);
	str = ft_strnew(1000);
	*line = str;
	remain = tmp->content;
	if (remain)
	{
		i = 0;
		while (remain[i] != '\n' && remain[i])
			i++;
		if (remain[i] == '\n' && i < (int)ft_strlen(remain))
		{
			ft_strncat(str, tmp->content, i);
			tmp->content = tmp->content + i + 1;
			return (1);
		}
		else
			ft_strcat(str, remain);
	}
	/*ft_putendl("-------");
	ft_putnbr(fd);
	ft_putnbr(tmp->fd);
	ft_putchar('\n');
	ft_putnbr(tmp->content_size);
	ft_putstr(tmp->content);
	ft_putchar('\n');
	ft_putendl("-------");*/
	while ((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[c_read] = '\0';
		while (buf[i] != '\n' && buf[i])
			i++;
		ft_strncat(str, buf, i);
		if (buf[i] == '\n' && i < BUFF_SIZE)
		{
			tmp->content = malloc(sizeof(char) * BUFF_SIZE - i);
			ft_strncpy(tmp->content, buf + i + 1, BUFF_SIZE - i);
			free(buf);
			return (1);
		}
	}
	if (c_read == 0)
	{
		if (ft_strlen(str) > 0)
		{
			if (remain)
				ft_bzero(remain, ft_strlen(remain));
			return (1);
		}
		free(str);
		return (0);
	}
	return (-1);
}
