/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nix <nix@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:42:50 by nix               #+#    #+#             */
/*   Updated: 2025/02/06 21:43:13 by nix              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s && s[i])
		i++;
	return i;
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return NULL;
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return NULL;
}

char *ft_strdup(const char *s)
{
	size_t len = ft_strlen(s);
	char *dup = malloc(len + 1);
	size_t i;
	if (!dup)
		return NULL;
	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[i] = '\0';
	return dup;
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *join = malloc(len1 + len2 + 1);
	size_t i, j;
	if (!join)
		return NULL;
	for (i = 0; i < len1; i++)
		join[i] = s1[i];
	for (j = 0; j < len2; j++)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return join;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len = ft_strlen(s);
	char *sub;
	size_t i;
	if (start >= s_len)
		return ft_strdup("");
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return NULL;
	for (i = 0; i < len; i++)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return sub;
}