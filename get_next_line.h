/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nix <nix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:37:15 by nix               #+#    #+#             */
/*   Updated: 2025/02/06 21:37:22 by nix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_list
{
	char			*result[1024];
	size_t			nulling;
	size_t		totallen;

}		t_list;

char	*ft_remainder(t_list **lst, int fd, ssize_t len, size_t max);
char	*ft_strjoin(const char *a, const char *b);
size_t	search(t_list **lst, int fd);
char	*finish(t_list **lst, ssize_t len, int fd);
char	*get_next_line(int fd);

#endif