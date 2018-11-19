/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:11 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/19 12:59:36 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		fd1;
	int		fd2;

	if (argc < 2)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line_fd(fd, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
		close(fd);
	}
	else if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd = fd1;
		while (get_next_line_fd(fd, &line) == 1)
		{
			fd = fd2;
			ft_putendl(line);
			free(line);
		}
		close(fd2);
		fd = fd1;
		while (get_next_line_fd(fd, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
		close(fd1);
	}
	return (0);
}
