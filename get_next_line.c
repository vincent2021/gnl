/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:22:15 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/08 14:57:10 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list			*ft_list_mgmt(t_list *gnl, const int fd, char *str)
{
	t_list		*tmp;

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

char			*ft_split(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n' && str[i + 1] != '\0')
	{
		str = str + i + 1;
		return (ft_strdup(str));
	}
	return (ft_strnew(1));
}

int				get_next_line(const int fd, char **line)
{
	char		*buf;
	char		*str;
	static char	*remain;
	int		i;
	int		c_read;

	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (line == NULL || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	str = ft_strnew(1000);
	*line = str;
	ft_putstr("Remain_GNL_1:");
	ft_putendl(remain);
	if (!remain)
		remain = ft_strnew(100);
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
	ft_putstr("Remain_GNL_2:");
	ft_putendl(remain);
	while ((c_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		i = 0;
		buf[BUFF_SIZE + 1] = '\0';
		while (buf[i] != '\n' && buf[i])
			i++;
		ft_strncat(str, buf, i);
		if (buf[i] == '\n' && i < BUFF_SIZE)
		{
			ft_strncpy(remain, buf + i + 1, BUFF_SIZE - i);
			return (1);
		}
	}
	ft_putnbr(ft_strlen(str));
	ft_putchar('/');
	ft_putnbr(c_read);
	ft_putchar('/');
	ft_putnbr(ft_strlen(remain));
	ft_putchar('\n');
	ft_putstr("Remain_GNL_3:");
	ft_putendl(remain);
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
