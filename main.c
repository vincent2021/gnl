/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:11 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/17 13:47:23 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char *line;
	int		fd;

	if(argc != 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	while (get_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	return(0);
	if (argc == 2)
		close(fd);
	return(0);
}
