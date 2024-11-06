/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:13:46 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 11:14:46 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_point(unsigned int **map)
{
	int	c;

	c = 0;
	while (c < 65)
	{
		free(map[c]);
		c++;
	}
	free(map);
}

void	close_free(t_cub3d *cube)
{
	if (cube->map.i_e)
		free_point(cube->map.i_e);
	if (cube->map.i_w)
		free_point(cube->map.i_w);
	if (cube->map.i_n)
		free_point(cube->map.i_n);
	if (cube->map.i_s)
		free_point(cube->map.i_s);
	if (cube->map.points)
		ft_freesplit(cube->map.points);
	if (cube->map.file_map)
		ft_freesplit(cube->map.file_map);
}

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_freesplitint(int **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_strjoinfree(char *str1, char *str2, int flag)
{
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	if (flag == 1)
		free(str1);
	if (flag == 2)
		free(str2);
	if (flag == 3)
	{
		free(str1);
		free(str2);
	}
	return (str3);
}

char	*ft_strtrim_free(char *s1, char const *set)
{
	int		left;
	int		right;
	int		c;
	char	*ptr;

	left = 0;
	c = 0;
	right = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[left]) != NULL)
		if (s1[left++] == '\0')
			return (ft_null(ptr = malloc(1)));
	while (ft_strchr(set, s1[right]) != NULL)
		right--;
	ptr = ft_calloc(sizeof(char), (right - left) + 2);
	if (ptr == NULL)
		return (NULL);
	right++;
	while (left != right)
		ptr[c++] = s1[left++];
	free(s1);
	return (ptr);
}

char	*ft_null(char *ptr)
{
	ptr[0] = '\0';
	return (ptr);
}

int	ft_double_pointer_counter1(char **dp, int line_counter)
{
	int	c;

	c = 0;
	while (dp[line_counter][c] != '\0')
		c++;
	return (c);
}

int	ft_double_pointer_counter2(char **dp)
{
	int	line_counter;

	line_counter = 0;
	while (dp[line_counter] != NULL)
		line_counter++;
	return (line_counter);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	c;

	c = 0;
	while (s1[c] && s2[c])
	{
		if ((unsigned char)s1[c] != (unsigned char)s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		c++;
	}
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
