/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:29:37 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:56:16 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_valid(t_cub3d *cub3d, int row, int colom)
{
	check_updown(cub3d, row, colom);
	check_leftright(cub3d, row, colom);
}

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
				check_valid(cub3d, row, colom);
			colom++;
		}
		row++;
	}
}

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

char	*get_pl(t_cub3d *cub3d, int c, char *str)
{
	cub3d->player.p_angle = -1;
	if (ft_strchr(cub3d->map.points[c], 'N') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'N');
		cub3d->player.p_angle = 270;
	}
	if (ft_strchr(cub3d->map.points[c], 'S') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'S');
		cub3d->player.p_angle = 90;
	}
	if (ft_strchr(cub3d->map.points[c], 'E') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'E');
		cub3d->player.p_angle = 180;
	}
	if (ft_strchr(cub3d->map.points[c], 'W') != NULL)
	{
		str = ft_strchr(cub3d->map.points[c], 'W');
		cub3d->player.p_angle = 0;
	}
	if (cub3d->player.p_angle < 0
		|| (ft_strlen(str) != ft_strlen(ft_strrchr(str, str[0]))))
		error(cub3d, 3);
	return (str);
}

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

/*
This code file contains functions for map validation and player positioning in a 3D raycasting game. Let's break down each function:
check_valid:
Calls check_updown and check_leftright to validate a specific position on the map.
map_checker:
Iterates through the entire map.
Calls check_valid for each '0' (open space) in the map to ensure it's properly enclosed.
map_size:
Determines the width and height of the map.
Width is set to the length of the longest row.
Height is the number of rows in the map.
get_pl:
Determines the player's starting position and angle based on the character in the map ('N', 'S', 'E', 'W').
Sets the player's angle accordingly (270 for 'N', 90 for 'S', 180 for 'E', 0 for 'W').
Checks for multiple player positions and triggers an error if found.
check_player_exist:
Verifies that a player starting position exists in the map.
Triggers an error if no player position is found.
Key points:
The map validation ensures that all open spaces are enclosed by walls.
The player's starting position and direction are determined from the map.
The code assumes a specific angle convention (0 is West, 90 is South, etc.).
Error handling is done by calling an error function with specific error codes.
*/