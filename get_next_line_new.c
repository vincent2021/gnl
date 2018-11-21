/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:23:55 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/21 16:56:17 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_get_mem(const int fd, t_gnl mem)
{
	t_gnl			



int					get_next_line_new(const int fd, char **line)
{
	size_t			i;
	char			*buf;
	size_t			c_read;
	static t_gnl	*mem;
	char			*str;

	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!mem)
		mem = malloc(sizeof(t_gnl);
	if (!buf || !mem || line == NULL || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	str = ft_get_mem(fd, mem)
	

}

