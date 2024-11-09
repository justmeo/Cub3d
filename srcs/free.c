/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:14 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:17 by fmaqdasi         ###   ########.fr       */
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
		free_split(cube->map.points);
	if (cube->map.file_map)
		free_split(cube->map.file_map);
}

void	free_split(char **split)
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

char	*free_extra_strings(char *str1, char *str2, int state)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	if (state == 0)
		free(str2);
	return (temp);
}

//to be changed
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
