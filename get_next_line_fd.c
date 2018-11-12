/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:22:15 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/12 17:19:47 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_lst_new(char *str, size_t fd)
{

}

t_gnl			*ft_lst_mgmt(t_gnl *mem, char *str, size_t fd)
{
	t_gnl		*tmp;

	tmp = mem;
	while (tmp)
	{
		if ((size_t)fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lst_add(str, fd);
	return (tmp);
}

int					get_next_line_fd(const int fd, char **line)
{
	char			*buf;
	char			*str;
	char			*remain = NULL;
	int				i;
	int				c_read;
	static t_gnl	*mem;

	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (line == NULL || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	if (!mem)
		mem = malloc (sizeof(t_gnl));
	str = ft_strnew(1000);
	*line = str;
	if (!remain)
	{
		remain = mem->content;
	}
	else
	{
		i = 0;
		while (remain[i] != '\n' && remain[i])
			i++;
		if (remain[i] == '\n' && i < (int)ft_strlen(remain))
		{
			ft_strncat(str, remain, i);
			remain = remain + i + 1;
			return (1);
		}
		else
			ft_strcat(str, remain);
	}
	ft_putendl("-------");
	ft_putnbr(mem->fd);
	ft_putchar('\n');
	ft_putnbr(mem->content_size);
	ft_putendl(mem->content);
	ft_putendl("-------");
	while ((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[c_read] = '\0';
		while (buf[i] != '\n' && buf[i])
			i++;
		ft_strncat(str, buf, i);
		if (buf[i] == '\n' && i < BUFF_SIZE)
		{
			ft_strncpy(remain, buf + i + 1, BUFF_SIZE - i);
			free(buf);
			return (1);
		}
	}
	if (c_read == 0)
	{
		if (ft_strlen(str) > 0)
		{
			ft_bzero(remain, ft_strlen(remain));
			return (1);
		}
		free(str);
		return (0);
	}
	return (-1);
}
