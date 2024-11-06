/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:20:49 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 12:48:52 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init(t_cub3d *cube)
{
	cube->map.points = NULL;
	cube->map.file_map = NULL;
	cube->map.t_n = NULL;
	cube->map.t_s = NULL;
	cube->map.t_e = NULL;
	cube->map.t_w = NULL;
	cube->map.i_n = NULL;
	cube->map.i_s = NULL;
	cube->map.i_e = NULL;
	cube->map.i_w = NULL;
}

void	free_map(t_cub3d *cube)
{
	if (cube->map.points != NULL)
		ft_freesplit(cube->map.points);
	if (cube->map.file_map != NULL)
		ft_freesplit(cube->map.file_map);
}

void	error(t_cub3d *cube, int flag)
{
	if (flag == 0)
		exit (1);
	if (flag == 1)
		ft_putstr_fd("Error: No File Name\n", 2);
	if (flag == 2)
		ft_putstr_fd("Error: Map wrong\n", 2);
	if (flag == 3)
		ft_putstr_fd("Error: Wrong number of players\n", 2);
	if (flag == 4)
		ft_putstr_fd("Error: Ceiling or Floor, wrong color\n", 2);
	if (flag == 5)
		ft_putstr_fd("Error: Textures doesn't exist\n", 2);
	if (flag == 6)
		ft_putstr_fd("Error: Map has empty line\n", 2);
	if (flag == 7)
		ft_putstr_fd("Error: Map bad\n", 2);
	if (flag == 8)
		ft_putstr_fd("Error: Empty file\n", 2);
	close_free(cube);
	exit(1);
}

void	valid_line(char *string, t_cub3d *cube, char *freeme)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (valid_letter(string[i]))
		{
			free (freeme);
			error(cube, 2);
		}
		i++;
	}
}

void	mapread(t_cub3d *cub3d, int start)
{
	int		c;
	char	*str;

	c = start;
	str = ft_strdup(cub3d->map.file_map[c]);
	while (cub3d->map.file_map[c])
	{
		valid_line(cub3d->map.file_map[c], cub3d, str);
		str = ft_strjoinfree(str, "\n", 1);
		str = ft_strjoinfree(str, cub3d->map.file_map[c], 1);
		c++;
	}
	str = ft_strtrim_free(str, "\n");
	cub3d->map.points = ft_split(str, '\n');
	free(str);
	check_player_exist(cub3d);
	map_size(cub3d);
	if (cub3d->map.height > 56
		|| cub3d->map.height <= 2 || cub3d->map.width <= 2)
		error(cub3d, 7);
	map_checker(cub3d);
	player_info(cub3d);
}

/*
This code file contains functions for error handling, initialization, and map processing in a 3D raycasting game. Let's break down each function:
init:
Initializes the main game structure (t_cub3d) by setting pointers to NULL.
This prevents undefined behavior when trying to free uninitialized pointers later.
free_map:
Frees the memory allocated for the map data.
Uses a custom ft_freesplit function, likely to free a 2D array.
error:
Handles various error conditions with descriptive messages.
Each error is associated with a flag number.
After printing the error message, it calls close_free and exits the program.
valid_line:
Checks if a line in the map file contains only valid characters.
Uses a helper function valid_letter (not shown here).
If an invalid character is found, it frees memory and calls the error function.
mapread:
Reads and processes the map data from the file.
Concatenates map lines into a single string, then splits it into a 2D array.
Performs various checks on the map:
Checks for player existence
Calculates map size
Verifies map dimensions
Calls map_checker for further validation
Sets up player information
Key points:
The code uses custom memory management functions (e.g., ft_strjoinfree, ft_strtrim_free).
There's a strong emphasis on error checking and graceful error handling.
The map is stored both as a single string and as a 2D array for different processing needs.
*/