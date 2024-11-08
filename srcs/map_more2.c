/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:15:53 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 12:53:36 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*readfile(int fd)
{
	char	*ntext;
	char	*text;
	bool	flag;

	text = get_next_line(fd);
	ntext = get_next_line(fd);
	flag = false;
	while (ntext != NULL)
	{
		text = ft_strjoinfree(text, ntext, 3);
		ntext = get_next_line(fd);
		if (flag && ntext && ft_strlen(ntext) == 1)
		{
			free(ntext);
			ntext = ft_strdup("00000");
			continue ;
		}
		if (ntext && ft_strncmp("NO", ntext, 2) && ft_strncmp("SO", ntext, 2)
			&& ft_strncmp("EA", ntext, 2) && ft_strncmp("WE", ntext, 2)
			&& ft_strncmp("F", ntext, 1) && ft_strncmp("C", ntext, 1)
			&& ft_strlen(ntext) > 1)
			flag = true;
	}
	return (text);
}

float	dist(t_point player, t_point ray, float angle)
{
	(void) angle;
	return (sqrt(((ray.x - player.x) * (ray.x - player.x))
			+ ((ray.y - player.y) * (ray.y - player.y))
		));
}

void	initialize_cast(t_cast *cast, t_cub3d *cube)
{
	cast->rays = 0;
	cast->r_angle = cube->player.p_angle - 30;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	cast->lines.x = 800;
	cast->lines.y = 0;
	cast->height.x = 800;
}

void	door_or_wall(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		wall_text_v(cast->height, cast->lines, cube, cast);
	else
		render_horizontal_wall_texture(cast->height, cast->lines, cube, cast);
}

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
	if ((spl[0] && spl[1] && spl[2])
		&& (check_digit(ft_strtrim(spl[0], " ")) == 1)
		&& (check_digit(ft_strtrim(spl[1], " ")) == 1)
		&& (check_digit(ft_strtrim(spl[2], " ")) == 1))
		ret = create_trgb(1, ft_atoi(spl[0]), ft_atoi(spl[1]), ft_atoi(spl[2]));
	else
	{
		ft_freesplit(spl);
		return (-1);
	}
	ft_freesplit(spl);
	return (ret);
}

/*
This code file contains several utility functions for a 3D raycasting game. Let's break down each function:
readfile:
Reads a file line by line using get_next_line.
Concatenates all lines into a single string.
Handles special cases for map parsing, including empty lines and texture definitions.
dist:
Calculates the Euclidean distance between two points (player and ray endpoint).
Uses the Pythagorean theorem.
initialize_cast:
Sets up initial values for the raycasting process.
Initializes the ray angle, number of rays, and screen dimensions.
door_or_wall:
Determines whether to render a vertical or horizontal wall texture based on which intersection (vertical or horizontal) is closer.
get_color:
Parses a color string in the format "R,G,B".
Validates that there are exactly three color components.
Checks if each component is a valid digit.
Creates an RGB color value using create_trgb function.
Key points:
The readfile function handles complex file parsing, including special cases for map layout.
Distance calculation is crucial for determining wall heights in raycasting.
The raycasting process is initialized with a 60-degree field of view (30 degrees on each side of the player's angle).
Color parsing includes validation to ensure the correct format and valid numeric values.
*/