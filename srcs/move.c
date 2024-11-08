/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:11:15 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 19:34:51 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	condition(t_cub3d *cube)
{
	int	x;
	int	y;

	x = cube->player.p_y;
	y = cube->player.p_x;
	if (cube->map.points[x / 64][y / 64] == '1' || cube->map.points[(x - 15)
		/ 64][(y - 15) / 64] == '1' || cube->map.points[(x) / 64][(y - 15)
		/ 64] == '1' || cube->map.points[(x - 15) / 64][(y) / 64] == '1'
		|| cube->map.points[(x + 15) / 64][(y + 15) / 64] == '1'
		|| cube->map.points[(x) / 64][(y + 15) / 64] == '1'
		|| cube->map.points[(x + 15) / 64][(y) / 64] == '1'
		|| cube->map.points[(x - 15) / 64][(y + 15) / 64] == '1'
		|| cube->map.points[(x + 15) / 64][(y - 15) / 64] == '1')
		return (true);
	return (false);
}

void	check_boundaries(t_cub3d *cube)
{
	if (cube->dir.a)
	{
		cube->player.p_x += cube->player.p_dy;
		if (condition(cube))
			cube->player.p_x -= cube->player.p_dy;
		cube->player.p_y -= cube->player.p_dx;
		if (condition(cube))
			cube->player.p_y += cube->player.p_dx;
	}
	if (cube->dir.d)
	{
		cube->player.p_x -= cube->player.p_dy;
		if (condition(cube))
			cube->player.p_x += cube->player.p_dy;
		cube->player.p_y += cube->player.p_dx;
		if (condition(cube))
			cube->player.p_y -= cube->player.p_dx;
	}
}

int	move(t_cub3d *cube)
{
	change_angle(cube);
	cube->player.p_dx = -cos(deg2rad(cube->player.p_angle)) * 1;
	cube->player.p_dy = sin(deg2rad(cube->player.p_angle)) * 1;
	if (cube->dir.w)
	{
		cube->player.p_x += cube->player.p_dx;
		if (condition(cube))
			cube->player.p_x -= cube->player.p_dx;
		cube->player.p_y += cube->player.p_dy;
		if (condition(cube))
			cube->player.p_y -= cube->player.p_dy;
	}
	if (cube->dir.s)
	{
		cube->player.p_x -= cube->player.p_dx;
		if (condition(cube))
			cube->player.p_x += cube->player.p_dx;
		cube->player.p_y -= cube->player.p_dy;
		if (condition(cube))
			cube->player.p_y += cube->player.p_dy;
	}
	check_boundaries(cube);
	render_map(cube);
	return (0);
}

/*
This code file implements player movement and collision detection for a 3D raycasting game. Let's break down each function:
condition:
Checks if the player is colliding with walls.
Checks multiple points around the player (center and 8 surrounding points) to prevent clipping through corners.
Returns true if any of these points intersect with a wall ('1' in the map).
check_boundaries:
Handles lateral movement (left and right strafing).
Moves the player perpendicular to their facing direction.
Uses the condition function to check for collisions and reverses movement if a collision occurs.
move:
The main function for handling player movement.
Calls change_angle and change_position (defined elsewhere) to update the player's orientation.
Handles forward and backward movement.
Uses the condition function to check for collisions and reverses movement if a collision occurs.
Calls check_boundaries for lateral movement.
Calls draw_map to update the game display after movement.
Key points:
The game uses a tile-based map where each tile is 64x64 pixels.
Collision detection is done by checking multiple points around the player to prevent corner clipping.
Movement is broken down into x and y components,
	allowing for sliding along walls.
The code supports four-directional movement (forward, backward, left,
	right) plus rotation.
*/