/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:22:15 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/09 17:20:30 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_lst(t_list *gnl, const int fd, char *str)
{
	t_list			*tmp;

	tmp = gnl;
	while (tmp)
	{
		if ((size_t)fd == tmp->content_size)
			return (tmp->content);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(str, fd);
	ft_lstadd(&gnl, tmp);
	return (tmp->content);
}

int					get_next_line_fd(const int fd, char **line)
{
	char			*buf;
	char			*str;
	static char		*remain;
	int				i;
	int				c_read;
	static t_list	*gnl;

	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (line == NULL || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	str = ft_strnew(1000);
	*line = str;
	if (!remain)
		remain = ft_strnew(1000);
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
			ft_lst(gnl, fd, remain);
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
