/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nix <nix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 06:39:37 by tschofma          #+#    #+#             */
/*   Updated: 2025/02/05 00:40:25 by nix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <fcntl.h>


char	*ft_remainder(t_list **lst, int fd, ssize_t len, size_t max)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	rest = malloc((max - len) + 1);
	if (!rest)
		return (NULL);
	while (i <= (max - len))
		rest[i++] = 0;
	while ((*lst)->result[fd][len + ++j] && len + j < max)
		rest[j] = (*lst)->result[fd][len + j];
	return (rest);
}

char	*ft_strjoin(const char *a, const char *b)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (a && a[i])
		i++;
	j = 0;
	while (b && b[j])
		j++;
	new = malloc(i + j + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (a && a[i])
		new[i++] = a[j++];
	j = 0;
	while (b && b[j])
		new[i++] = b[j++];
	new[i] = 0;
	return (new);
}

size_t	search(t_list **lst, int fd)
{
	size_t		i;
	ssize_t		nl;
	ssize_t		rd;
	char		*temp;

	nl = -1;
	while ((*lst)->result[fd] && (*lst)->result[fd][++nl])
		if ((*lst)->result[fd][nl] == '\n')
			return ((*lst)->totallen + nl);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
		temp[i++] = 0;
	rd = read(fd, temp, BUFFER_SIZE);
	if (rd <= 0)
		return (nl);
	(*lst)->result[fd] = ft_strjoin((*lst)->result[fd], temp);
	nl = -1;
	while ((*lst)->result[fd][(*lst)->totallen + ++nl])
		if ((*lst)->result[fd][(*lst)->totallen + nl] == '\n' || (!(*lst)->
			result[fd][(*lst)->totallen + nl] && rd != BUFFER_SIZE))
			return ((*lst)->totallen + nl);
	return (free(temp), temp = NULL, (*lst)->totallen += nl, search(lst, fd));
}

char	*finish(t_list **lst, ssize_t len, int fd)
{
	char	*output;
	ssize_t	max;
	ssize_t	i;

	(*lst)->totallen = 0;
	max = 0;
	if ((!(*lst)->result[fd]) && len <= 0)
		return (NULL);
	while ((*lst)->result[fd][max])
		max++;
	i = -1;
	output = malloc(len + 1);
	if (!output)
		return (NULL);
	while (++i <= len && i < max && (*lst)->result[fd][i])
		output[i] = (*lst)->result[fd][i];
	output[i] = 0;
	if (len >= max) 
		return (free((*lst)->result[fd]), (*lst)->result[fd] = NULL, output);
	if (len < max)
		return ((*lst)->result[fd] = ft_remainder(lst, fd, i, max), output);
	return (output);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*final;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!lst)
	{
		lst = malloc(sizeof(t_list));
		if (!lst)
			(free(lst), lst = NULL);
		lst->nulling = 0;
		while (lst->nulling < 1024)
			lst->result[lst->nulling++] = NULL;
	}
	final = finish(&lst, search(&lst, fd), fd);
	return (final);
}
// int main(void)
// {
//     int fd1 = open("test", O_RDONLY);
//     int fd2 = open("test2", O_RDONLY);
//     char *line;

//     //Read lines alternately from fd1 and fd2
//     while (1)
// 	{
//         line = get_next_line(fd1);
//         if (line)
// 		{
//             printf("FD1: %s", line);
//             free(line);
//         }
//         line = get_next_line(fd2);
//         if (line) {
//             printf("FD2: %s", line);
//             free(line);
//         }
//         if (!line) // Break when both fds reach EOF
//             break;
//     }
//     close(fd1);
//     close(fd2);
//     return (0);
//  }