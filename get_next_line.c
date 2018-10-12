/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:26:08 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/12 17:36:03 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char	*buf;

	buf = malloc(sizeof(char)*(BUF_SIZE+1));
	read(fd, line[0], BUF_SIZE);
	read(fd, buf, BUF_SIZE);
	buf[BUF_SIZE+1] = '\0';

	ft_putstr("Line:\n");	
	ft_putstr(line[0]);
	ft_putstr("\n");
	ft_putstr("Buffer: \n");
	ft_putstr(buf);

	return(0);
}
