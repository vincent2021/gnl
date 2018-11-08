/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:11 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/26 10:25:55 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	if (argc != 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((i = get_next_line(fd, &line)) == 1)
	{
		ft_putnbr(i);
		ft_putchar('.');
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
