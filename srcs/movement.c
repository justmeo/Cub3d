/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:35 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:42:44 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// to be changed
bool	condition(t_cub3d *cube)
{
	int	x;
	int	y;

	x = cube->player_y;
	y = cube->player_x;
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

// to be changed
void	check_boundaries(t_cub3d *cube)
{
	if (cube->movement_a)
	{
		cube->player_x += cube->player_dy;
		if (condition(cube))
			cube->player_x -= cube->player_dy;
		cube->player_y -= cube->player_dx;
		if (condition(cube))
			cube->player_y += cube->player_dx;
	}
	if (cube->movement_d)
	{
		cube->player_x -= cube->player_dy;
		if (condition(cube))
			cube->player_x += cube->player_dy;
		cube->player_y += cube->player_dx;
		if (condition(cube))
			cube->player_y -= cube->player_dx;
	}
}

// to be changed
int	move(t_cub3d *cube)
{
	change_angle(cube);
	cube->player_dx = -cos(deg_to_rad(cube->player_angle)) * 1;
	cube->player_dy = sin(deg_to_rad(cube->player_angle)) * 1;
	if (cube->movement_w)
	{
		cube->player_x += cube->player_dx;
		if (condition(cube))
			cube->player_x -= cube->player_dx;
		cube->player_y += cube->player_dy;
		if (condition(cube))
			cube->player_y -= cube->player_dy;
	}
	if (cube->movement_s)
	{
		cube->player_x -= cube->player_dx;
		if (condition(cube))
			cube->player_x += cube->player_dx;
		cube->player_y -= cube->player_dy;
		if (condition(cube))
			cube->player_y += cube->player_dy;
	}
	check_boundaries(cube);
	render_map(cube);
	return (0);
}
