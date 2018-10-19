/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:22:15 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/19 16:24:29 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_list_mgmt(t_list *gnl, const int fd, char *str)
{
	t_list	*tmp;

	tmp = gnl;
	while (tmp)
	{
		if ((size_t)fd == tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(str, fd);
	ft_lstadd(&gnl, tmp);
	return (tmp);
}

int	get_next_line(const int fd, char **line)
{
	char			*buf;
	char			*str;
	static char		*remain;
	int			i;
	int			c_read;

	str = ft_strnew(1000);
	if (!remain)
		remain = ft_strnew(100);
	*line = str;	
	if (!(buf = malloc(sizeof(char)*(BUFF_SIZE + 1))))
		return (-1);
	if (line == NULL || read(fd, buf, 0) == -1)
		return (-1);
	while((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[BUFF_SIZE + 1] = '\0';
		while (buf[i] != '\n' && buf[i])			
			i++;
		if (ft_strlen(remain) > 0)
			ft_strncat(str, remain, ft_strlen(remain));
		ft_strncat(str, buf, i);
		if (buf[i] == '\n')
		{
			str = ft_strncpy(remain, buf + i + 1, BUFF_SIZE - i);
			return (1);
		}
	}
	if (c_read == 0 && ft_strlen(remain) == 0)
		return (0);
	else if (c_read == 0 && ft_strlen(remain) > 0)
	{
		ft_strncat(str, remain, ft_strlen(remain) - 1);
		remain[0] = '\0';
		return (1);
	}
	return (-1);
}
