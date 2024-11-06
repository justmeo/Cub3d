/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:18:13 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 19:27:52 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_booleans(t_cub3d *cube)
{
	cube->dir.w = false;
	cube->dir.s = false;
	cube->dir.a = false;
	cube->dir.d = false;
	cube->dir.left = false;
	cube->dir.right = false;
	cube->m = false;
}

void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	str = readfile(fd);
	if (!str)
		error(cub3d, 8);
	cub3d->map.file_map = ft_split(str, '\n');
	free(str);
	texture_parse(cub3d);
	cub3d->player.p_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player.p_y = cub3d->map.p_row * 64 + 32;
	cub3d->player.p_dx = cos(cub3d->player.p_angle) * 1;
	cub3d->player.p_dy = sin(cub3d->player.p_angle) * 1;
}

/*
This code file contains two important functions for initializing and setting up the game environment in a 3D raycasting game. Let's break down each function:
set_booleans:
Initializes various boolean flags in the game structure.
Sets movement directions (w, s, a, d) to false.
Sets rotation directions (left, right) to false.
Initializes other game state flags (m, shift) to false.
openmap:
Opens and reads the map file specified in the command line arguments.
Uses the readfile function (defined elsewhere) to read the entire file content.
Splits the file content into lines and stores them in cub3d->map.file_map.
Calls texture_parse to process texture and color information.
Sets the initial player position based on the map data.
Initializes the player's direction vector based on their initial angle.
Key points:
The set_booleans function ensures all movement and state flags start in a known (false) state.
The openmap function handles the entire process of loading and initial processing of the map file.
Player position is set in terms of pixel coordinates (multiplying map coordinates by 64 and adding 32 for center positioning).
Initial player direction is set using cosine and sine functions.
*/