/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:11:04 by fgroo             #+#    #+#             */
/*   Updated: 2025/11/10 23:46:54 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# ifndef BUF
#  define BUF BUFFER_SIZE
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_vars
{
	char	buf[1024][100000];
	char	tmp[1024][100000];
	ssize_t	pos[1024];
	ssize_t	rd[1024];
	char	*res;
}	t_vars;

typedef struct s_tmp
{
	ssize_t	len;
	ssize_t	i;
	char	*res;
}	t_tmp;

char	*get_next_line(int fd);

#endif