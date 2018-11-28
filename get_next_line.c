/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:24:52 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/28 13:33:43 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*ft_lst_new(int fd, t_gnl *mem)
{
	t_gnl	*new;

	if (!(new = malloc(sizeof(t_gnl))))
		return (0);
	new->fd = fd;
	new->content = NULL;
	new->next = mem;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*mem = NULL;
	t_gnl			tmp;

	if (line == NULL || read(fd, NULL, 0) == -1 || fd < 0)
		return (-1);
	if (!mem)
		ft_lst_new(fd, NULL);
	return (0);
}
