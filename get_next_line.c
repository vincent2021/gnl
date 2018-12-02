/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:24:52 by vimucchi          #+#    #+#             */
/*   Updated: 2018/12/02 23:50:34 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_getline(t_gnl *mem, char **line, int c_read)
{
	size_t			i;
	size_t			len;
	char			*tmp;

	i = 0;
	len = ft_strlen (mem->content);
	while (mem->content[i] != '\n' && mem->content[i])
		i++;
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putendl("<= i get_line");
	if (mem->content[i] == '\n' || (c_read == 0 && i == len))
	{
		*line = ft_strnew(i);
		ft_strncpy(*line, mem->content, i);
		ft_putnbr(len);
		ft_putendl("<=len mem->content");
		if (i == len - 1)
			ft_strdel(&mem->content);
		else 
		{
			tmp = ft_strdup(mem->content + i + 1);
			ft_strdel(&mem->content);
			ft_putendl(tmp);
			mem->content = tmp;
		}
		return (1);
	}
	return (0);
}

void				ft_cpybuf(t_gnl *mem, char *buf)
{
	char			*tmp;

	if (!mem->content)
		mem->content = ft_strdup(buf);
	else
	{
		tmp = mem->content;
		mem->content = ft_strjoin(mem->content, buf);
		ft_strdel(&tmp);
	}
}

int					ft_read(int fd, char **line, t_gnl *mem)
{
	char			*buf;
	size_t			c_read;

	if (!(buf = malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((c_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[c_read] = '\0';
		ft_putnbr(c_read);
		ft_putendl("<= c_read");
		ft_cpybuf(mem, buf);
		if (ft_getline(mem, line, c_read))
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	while (ft_getline(mem, line, 0) == 1)
	{
		ft_strdel(&buf);
		ft_putendl("-------------end--------------");
		return (1);
	}
	free(buf);
	ft_putendl(mem->content);
	return (0);
}

t_gnl				*ft_lst_new(int fd, t_gnl *mem)
{
	t_gnl			*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (0);
	new->fd = fd;
	new->content = NULL;
	new->next = mem;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*mem = NULL;
	t_gnl			*tmp;

	if (line == NULL || read(fd, NULL, 0) == -1 || fd < 0)
		return (-1);
	if (!mem)
		mem = ft_lst_new(fd, NULL);
	tmp = mem;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
		return (ft_read(fd, line, (mem = ft_lst_new(fd, mem))));
	ft_putendl("--------Start------");
	ft_putnbr(fd);
	ft_putchar('/');
	ft_putnbr(tmp->fd);
	ft_putendl(tmp->content);
	return (ft_read(fd, line, tmp));
}
