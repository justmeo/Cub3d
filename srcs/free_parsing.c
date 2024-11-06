/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:13:46 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 12:50:12 by fmaqdasi         ###   ########.fr       */
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
			return (ft_strdup(""));
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

int	ft_double_pointer_counter2(char **dp)
{
	int	line_counter;

	line_counter = 0;
	while (dp[line_counter] != NULL)
		line_counter++;
	return (line_counter);
}

/*
This code file contains several utility functions for memory management and string manipulation, specifically tailored for the needs of a 3D raycasting game. Let's break down each function:
free_point:
Frees a 2D array of unsigned integers, specifically sized 65x65.
Used for freeing texture data.
close_free:
Comprehensive cleanup function for the main game structure.
Frees texture data, map points, and file map data.
ft_freesplit:
Frees a 2D array of strings (char**).
ft_freesplitint:
Frees a 2D array of integers (int**).
ft_strjoinfree:
Joins two strings and optionally frees one or both of the input strings.
The flag parameter determines which strings to free:
1: free str1
2: free str2
3: free both str1 and str2
ft_strtrim_free:
Trims specified characters from the beginning and end of a string.
Frees the input string and returns a new allocated string.
ft_double_pointer_counter2:
Counts the number of elements in a NULL-terminated array of strings.
Key points:
These functions are designed to work with the specific data structures used in the game.
There's a strong emphasis on proper memory management, ensuring that allocated memory is freed.
Custom versions of standard library functions (like strjoin and strtrim) are implemented with additional memory management features.
*/