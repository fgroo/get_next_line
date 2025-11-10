/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:10:58 by fgroo             #+#    #+#             */
/*   Updated: 2025/11/10 23:48:09 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_vars	v;
	t_tmp			tmp;

	tmp = (t_tmp){0, -1, NULL};
	if (fd < 0 || !BUF || fd >= 1024 || (read(fd, 0, 0) < 0))
		return (v.rd[fd] = 0, NULL);
	while (1)
	{
		if (v.pos[fd] >= v.rd[fd] && v.rd[fd] != -1)
			(free(0), v.pos[fd] = 0, v.rd[fd] = read(fd, v.tmp[fd], BUF));
		if (!v.rd[fd])
			break ;
		v.buf[fd][tmp.len++] = v.tmp[fd][v.pos[fd]++];
		if (v.buf[fd][tmp.len - 1] == '\n')
			break ;
	}
	if (v.rd[fd] != -1 && tmp.len > 0)
	{
		tmp.res = malloc(tmp.len + 1);
		if (!tmp.res)
			return (NULL);
		while (++tmp.i < tmp.len && v.buf[fd][tmp.i])
			(free(0), tmp.res[tmp.i] = v.buf[fd][tmp.i], tmp.res[tmp.len] = 0);
	}
	return (tmp.res);
}
