/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:40:11 by vimucchi          #+#    #+#             */
/*   Updated: 2018/10/16 19:40:52 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char **line;
	char *str;

	line = malloc(sizeof(char*));
	if (argc == 2)
	{
		get_line(open(argv[1],O_RDONLY), line);
		ft_putstr("\nFrom main");
		str = *line;
		ft_putstr(str);
		ft_putchar('\n');
	}
	return(0);
}
