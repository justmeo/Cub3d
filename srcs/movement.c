/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:35 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:37 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//to be changed
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

//to be changed
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

//to be changed
int	move(t_cub3d *cube)
{
	change_angle(cube);
	cube->player.p_dx = -cos(deg_to_rad(cube->player.p_angle)) * 1;
	cube->player.p_dy = sin(deg_to_rad(cube->player.p_angle)) * 1;
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
