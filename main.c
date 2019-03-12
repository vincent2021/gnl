/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:11 by vimucchi          #+#    #+#             */
/*   Updated: 2019/03/12 16:21:41 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void		multiple_fd(char *argv1, char *argv2, char **line)
{
	int		fd1;
	int		fd2;
	int		fd;

	fd1 = open(argv1, O_RDONLY);
	fd2 = open(argv2, O_RDONLY);
	fd = fd1;
	while (get_next_line(fd, line) == 1)
	{
		fd = fd2;
		ft_putendl(*line);
	}
	close(fd2);
	fd = fd1;
	while (get_next_line(fd, line) == 1)
	{
		ft_putendl(*line);
	}
	close(fd1);
}

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc < 2)
	{
		fd = 0;
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
		close(fd);
	}
	else if (argc == 3)
	{
		multiple_fd(argv[1], argv[2], &line);
		free(line);
	}
	return (0);
}
