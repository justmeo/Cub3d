/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:27:50 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:55:21 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_digit(char *string)
{
	int	c;

	c = 0;
	while (string[c])
	{
		if (!ft_isdigit(string[c]))
		{
			free(string);
			return (0);
		}
		c++;
	}
	free(string);
	return (1);
}

int	valid_letter(char letter)
{
	if (letter == '0' || letter == 'N' || letter == 'S' || letter == 'E'
		|| letter == 'W' || letter == ' ' || letter == '1')
		return (0);
	return (1);
}

void	check_updown(t_cub3d *cub3d, int row, int colom)
{
	int	vert;

	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert--;
		if (vert < 0 || colom >= (int)ft_strlen(cub3d->map.points[vert])
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error(cub3d, 2);
	}
	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert++;
		if (vert >= cub3d->map.height
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error(cub3d, 2);
	}
}

int	check_leftright(t_cub3d *cub3d, int row, int colom)
{
	int	hor;

	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor--;
		if (hor < 0 || valid_letter(cub3d->map.points[row][hor]) == 1)
			error(cub3d, 2);
	}
	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor++;
		if (hor >= cub3d->map.width
			|| valid_letter(cub3d->map.points[row][hor]) == 1)
			error(cub3d, 2);
	}
	return (1);
}

/*
This code file contains utility functions for map parsing and validation in a 3D raycasting game. Let's break down each function:
create_trgb:
Creates a 32-bit color value from individual transparency, red, green, and blue components.
Uses bitwise operations to combine the color components.
check_digit:
Checks if a string contains only digit characters.
Returns 1 if the string is all digits, 0 otherwise.
Frees the input string, which is unusual and could lead to issues if the caller still needs the string.
valid_letter:
Checks if a character is a valid map element.
Returns 0 for valid characters ('0', 'N', 'S', 'E', 'W', ' ', '1'), 1 for invalid characters.
check_updown:
Checks the vertical integrity of the map at a given position.
Ensures that there are walls ('1') above and below any open space or player position.
Triggers an error if an invalid character or map edge is encountered before a wall.
check_leftright:
Similar to check_updown, but checks horizontal integrity.
Ensures that there are walls to the left and right of any open space or player position.
Returns 1 if the check passes, otherwise triggers an error.
Key points:
These functions are crucial for ensuring the map is properly enclosed and contains only valid characters.
The map validation assumes that the map is rectangular and that '1' represents walls.
Error handling is done by calling an error function with specific error codes.
*/