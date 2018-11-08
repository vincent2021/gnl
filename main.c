/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:11 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/08 14:47:16 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		r;

	if (argc != 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((r = get_next_line(fd, &line)) == 1)
	{
		ft_putstr("Return ");
		ft_putnbr(r);
		ft_putstr(" - Line ");
		ft_putnbr(i);
		ft_putchar('\n');
		i++;
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
