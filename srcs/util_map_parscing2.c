/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map_parscing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:18 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:38:58 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// to be changed
void	map_checker(t_cub3d *cub3d)
{
	int	row;
	int	colom;

	row = 0;
	while (cub3d->map.points[row])
	{
		colom = 0;
		while (cub3d->map.points[row][colom])
		{
			if (cub3d->map.points[row][colom] == '0')
			{
				check_updown(cub3d, row, colom);
				check_leftright(cub3d, row, colom);
			}
			colom++;
		}
		row++;
	}
}

// to be changed
void	map_size(t_cub3d *cub3d)
{
	int	c;
	int	c1;

	c = 0;
	c1 = 0;
	c1 = ft_strlen(cub3d->map.points[c]);
	while (cub3d->map.points[c])
	{
		if ((int)ft_strlen(cub3d->map.points[c]) > c1)
			c1 = ft_strlen(cub3d->map.points[c]);
		c++;
	}
	cub3d->map.width = c1;
	cub3d->map.height = c;
}

// to be changed
char	*get_pl(t_cub3d *cub3d, int c, char *str)
{
	cub3d->player_angle = -1;
	if (ft_strchr(cub3d->map.points[c], 'N') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'N');
		cub3d->player_angle = 270;
	}
	if (ft_strchr(cub3d->map.points[c], 'S') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'S');
		cub3d->player_angle = 90;
	}
	if (ft_strchr(cub3d->map.points[c], 'E') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'E');
		cub3d->player_angle = 180;
	}
	if (ft_strchr(cub3d->map.points[c], 'W') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'W');
		cub3d->player_angle = 0;
	}
	if (cub3d->player_angle < 0 || (ft_strlen(str) != ft_strlen(ft_strrchr(str,
					str[0]))))
		error(cub3d, 3);
	return (str);
}

// to be changed
void	check_player_exist(t_cub3d *cube)
{
	bool	flag;
	int		i;

	i = 0;
	flag = false;
	while (cube->map.points[i])
	{
		if (ft_strchr(cube->map.points[i], 'N')
			|| ft_strchr(cube->map.points[i], 'W')
			|| ft_strchr(cube->map.points[i], 'S')
			|| ft_strchr(cube->map.points[i], 'E'))
			flag = true;
		i++;
	}
	if (!flag)
		error(cube, 3);
}

// to be changed
int	get_color(char *line)
{
	char	**spl;
	int		c;
	int		ret;

	spl = ft_split(line, ',');
	if (line)
		free(line);
	c = 0;
	while (spl[c])
		c++;
	if (c != 3)
		return (-1);
	if ((spl[0] && spl[1] && spl[2]) && (check_digit(ft_strtrim(spl[0],
					" ")) == 1) && (check_digit(ft_strtrim(spl[1], " ")) == 1)
		&& (check_digit(ft_strtrim(spl[2], " ")) == 1))
		ret = create_trgb(1, ft_atoi(spl[0]), ft_atoi(spl[1]), ft_atoi(spl[2]));
	else
	{
		free_split(spl);
		return (-1);
	}
	free_split(spl);
	return (ret);
}
