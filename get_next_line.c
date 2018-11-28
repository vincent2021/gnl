/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:24:52 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/28 17:44:34 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_getline(t_gnl *mem, char **line)
{
	size_t			i;
	char			*tmp;

	i = 0;
	while (mem->content[i] != '\n' && mem->content[i])
		i++;
	if (mem->content[i] == '\n')
	{
		*line = ft_strnew(i);
		*line = ft_strncpy(*line, mem->content, i);
		if (i == ft_strlen(mem->content))
			ft_strdel(&mem->content);
		else
		{
			tmp = mem->content + i;
			ft_strdel(&mem->content);
			mem->content = ft_strdup(tmp);
		}
		return (1);
	}
	return (0);
}

int					ft_read(int fd, char **line, t_gnl *mem)
{
	char			*buf;
	size_t			c_read;
	char			*tmp;

	if (!(buf = malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[c_read] = '\0';
		if (!mem->content)
			mem->content = ft_strdup(buf);
		else
		{
			tmp = mem->content;
			mem->content = ft_strjoin(mem->content, buf);
			ft_strdel(&tmp);
		}
		if (ft_getline(mem, line))
			return (1);
	}
	if (ft_getline(mem, line))
		return (1);
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
	return (ft_read(fd, line, tmp));
}
