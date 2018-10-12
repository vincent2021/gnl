/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:57:44 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/12 18:28:34 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char	*buf;
	int		i;
	int		l;

	buf = malloc(sizeof(char)*(BUF_SIZE+1));
	
	i = 0;
	l = 0;
	while(line[l][i] != '\n')
	{
		read(fd,line[l], BUF_SIZE);
		ft_putnbr(l);
		ft_putnbr(i);
		ft_putstr(" - Line:\n");	
		ft_putstr(line[l]);
		ft_putstr("\n");
		i++;
	}
	l++;
	
	read(fd, buf, BUF_SIZE);
	buf[BUF_SIZE+1] = '\0';
	ft_putstr("Buffer: \n");
	ft_putstr(buf);

	return(0);
}
