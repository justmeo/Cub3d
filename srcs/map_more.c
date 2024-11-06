/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:25 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:52:18 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	player_check(t_cub3d *cub3d, int c)
{
	int	c1;

	c1 = 0;
	if (ft_strchr(cub3d->map.points[c], 'N') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[c], 'S') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[c], 'E') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[c], 'W') != NULL)
		c1++;
	return (c1 - 1);
}

void	player_info(t_cub3d *cub3d)
{
	char	*str;
	int		c;
	int		leter_count;

	c = 0;
	leter_count = 0;
	while (cub3d->map.points[c])
	{
		if (ft_strchr(cub3d->map.points[c], 'N') != NULL
			|| ft_strchr(cub3d->map.points[c], 'S') != NULL
			|| ft_strchr(cub3d->map.points[c], 'E') != NULL
			|| ft_strchr(cub3d->map.points[c], 'W') != NULL)
		{
			str = get_pl(cub3d, c, str);
			cub3d->map.p_row = c;
			cub3d->map.p_colom = ft_strlen(cub3d->map.points[c])
				- ft_strlen(str);
			leter_count += player_check(cub3d, c);
			leter_count++;
		}
		c++;
	}
	if (leter_count > 1)
		error(cub3d, 3);
}

int	texture_parse2(t_cub3d *cub3d, char *line, int c)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		cub3d->map.t_n = ft_strchr(cub3d->map.file_map[c], '.');
	else if (!ft_strncmp(line, "SO", 2))
		cub3d->map.t_s = ft_strchr(cub3d->map.file_map[c], '.');
	else if (!ft_strncmp(line, "EA", 2))
		cub3d->map.t_e = ft_strchr(cub3d->map.file_map[c], '.');
	else if (!ft_strncmp(line, "WE", 2))
		cub3d->map.t_w = ft_strchr(cub3d->map.file_map[c], '.');
	else if (!ft_strncmp(line, "F", 1))
		cub3d->map.f = get_color(ft_substr((cub3d->map.file_map[c]), 1,
					ft_strlen(cub3d->map.file_map[c])));
	else if (!ft_strncmp(line, "C", 1))
		cub3d->map.c = get_color(ft_substr((cub3d->map.file_map[c]), 1,
					ft_strlen(cub3d->map.file_map[c])));
	else
		return (1);
	return (0);
}

void	nuggets(t_cub3d *cube)
{
	t_dir	bol;
	int		c;

	c = 0;
	bol.w = false;
	bol.a = false;
	bol.s = false;
	bol.d = false;
	while (cube->map.file_map[c] && c < 4)
	{
		bol.w = (bol.w || (ft_strncmp(cube->map.file_map[c], "NO", 2) == 0));
		bol.a = (bol.a || (ft_strncmp(cube->map.file_map[c], "SO", 2) == 0));
		bol.s = (bol.s || (ft_strncmp(cube->map.file_map[c], "EA", 2) == 0));
		bol.d = (bol.d || (ft_strncmp(cube->map.file_map[c], "WE", 2) == 0));
		c++;
	}
	if (!bol.w || !bol.a || !bol.s || !bol.d)
		error(cube, 5);
}

void	texture_parse(t_cub3d *cub3d)
{
	int		c;
	char	*line;

	c = -1;
	while (cub3d->map.file_map[++c]
		&& ft_double_pointer_counter2(cub3d->map.file_map) > c)
	{
		line = ft_strtrim(cub3d->map.file_map[c], " ");
		if (texture_parse2(cub3d, line, c) == 1)
			break ;
		free (line);
	}
	if (ft_double_pointer_counter2(cub3d->map.file_map) <= c)
	{
		close_free(cub3d);
		exit (1);
	}
	if (line)
		free (line);
	if (cub3d->map.c == -1 || cub3d->map.f == -1)
		error(cub3d, 4);
	mapread(cub3d, c);
	nuggets(cub3d);
}
/*
This code file contains several functions related to map parsing and player positioning in a 3D raycasting game. Let's break down each function:
player_check:
Counts the number of player start positions (N, S, E, W) in a single line of the map.
Returns the count minus one (to allow for a single player position).
player_info:
Scans the entire map to find the player's starting position and orientation.
Sets the player's row and column in the map.
Ensures there's only one player start position in the entire map.
texture_parse2:
Parses a single line of the map file for texture and color information.
Sets texture paths for North, South, East, and West walls.
Parses floor and ceiling colors.
nuggets:
Checks if all required texture directions (NO, SO, EA, WE) are present in the map file.
If any are missing, it triggers an error.
texture_parse:
Main function for parsing texture and color information from the map file.
Calls texture_parse2 for each line until it reaches the actual map data.
Verifies that ceiling and floor colors are properly set.
Calls mapread to process the actual map data.
Calls nuggets to ensure all required textures are present.
Key points:
The code ensures that there's exactly one player start position in the map.
It parses texture paths and color information for the game environment.
There are checks to ensure all required map elements are present and valid.
*/