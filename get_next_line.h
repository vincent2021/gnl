/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <vimucchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:27:48 by vimucchi          #+#    #+#             */
/*   Updated: 2018/11/19 13:56:17 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 20

typedef struct		s_gnl
{
	char			*content;
	size_t			content_size;
	size_t			fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
int					get_next_line_fd(const int fd, char **line);

#endif
