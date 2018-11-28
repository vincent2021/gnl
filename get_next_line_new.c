/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:23:55 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/28 13:23:42 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_concat(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	len_s1;
	char	*tmp;

	i = 0;
	len_s1 = 0;
	if (s1 != NULL)
	{
		len_s1 = ft_strlen(s1);
		tmp = s1;
		free(s1);
		s1 = malloc ((len + len_s1 + 1) * sizeof(char));
		while (tmp[i])
		{
			s1[i] = tmp[i];
			i++;
		}
	}	
	else
		s1 = malloc((len + 1) * sizeof(char));
	while(s2[i - len_s1])
	{
		s1[i] = s2[i - len_s1];
		i++;
	}
	s1[i] = '\0';
	return (s1);	
}

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
		ft_concat(str, buf, i);
		if (buf[i] == '\n' && i < BUFF_SIZE)
		{
			mem->content = malloc(sizeof(char) * BUFF_SIZE - i);
			ft_strncpy(mem->content, buf + i + 1, BUFF_SIZE - i);
			free(buf);
			return (str);
		}
	}
	return (NULL);
}

int					get_next_line_new(const int fd, char **line)
{
	static t_gnl	*mem = NULL;
	t_gnl			*tmp;
	char			*str;

	if (!mem)
		mem = ft_lst_new(fd);
	if (!mem || line == NULL || fd < 0)
		return (-1);
	tmp = ft_get_mem(fd, mem);
	str = ft_read(tmp, fd);
	if (str)
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
