/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:51:30 by fmaqdasi          #+#    #+#             */
/*   Updated: 2023/08/05 12:43:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *ch, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		((unsigned char *)ch)[i] = 0;
		i++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*st;

	if (size != 0 && (count > UINT32_MAX / size))
		return (NULL);
	st = malloc(count * size);
	if (!st)
		return (NULL);
	ft_bzero(st, count * size);
	return (st);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*st;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	st = (char *)malloc(j + ft_strlen(s2) + 1);
	if (!st)
		return (NULL);
	while (s1[i])
	{
		st[i] = s1[i];
		i++;
	}
	while (s2[i - j])
	{
		st[i] = s2[i - j];
		i++;
	}
	st[i] = '\0';
	return (st);
}
