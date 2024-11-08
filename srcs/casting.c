/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:50:34 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:42:24 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_floor_ceiling(t_cub3d *cube)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.x = 800;
	end.y = 0;
	while (end.y < 400)
	{
		dda(start, end, cube, cube->map.c);
		end.y++;
		start.y++;
	}
	start.x = 0;
	start.y = 400;
	end.x = 800;
	end.y = 400;
	while (end.y < 800)
	{
		dda(start, end, cube, cube->map.f);
		end.y++;
		start.y++;
	}
}

void	set_horizontals(t_cub3d *cube, t_cast *cast)
{
	cast->dof = 0;
	if (cast->r_angle > 180)
	{
		cast->rayh.y = (((int) cube->player.p_y >> 6) << 6) - 0.0001;
		cast->rayh.x = (cube->player.p_y - cast->rayh.y)
			* (1 / tan(deg2rad(cast->r_angle))) + cube->player.p_x;
		cast->off.y = -64;
		cast->off.x = -cast->off.y * (1 / tan(deg2rad(cast->r_angle)));
	}
	else if ((int) cast->r_angle == 0 || (int) cast->r_angle == 180)
	{
		cast->rayh.x = cube->player.p_x;
		cast->rayh.y = cube->player.p_y;
		cast->dof = DOF;
		cast->disth = 100000;
	}
	else
	{
		cast->rayh.y = (((int) cube->player.p_y >> 6) << 6) + 64;
		cast->rayh.x = ((cube->player.p_y - cast->rayh.y)
				* (1 / tan(deg2rad(cast->r_angle)))) + cube->player.p_x;
		cast->off.y = 64;
		cast->off.x = -cast->off.y * (1 / tan(deg2rad(cast->r_angle)));
	}
}

void	set_rayh(t_cub3d *cube, t_cast *cast)
{
	while (cast->dof++ < DOF)
	{
		cast->disth = 100000;
		if (cast->rayh.y / 64 < cube->map.height && cast->rayh.y / 64 >= 0
			&& cast->rayh.x / 64 < cube->map.width && cast->rayh.x / 64 >= 0
			&& (cube->map.points[(int)(cast->rayh.y / 64)]
			[(int)(cast->rayh.x / 64)] == '1')
			)
		{
			cast->disth = dist(cast->player, cast->rayh, cast->r_angle);
			cast->dof = DOF;
		}
		else
		{
			cast->rayh.x += cast->off.x;
			cast->rayh.y += cast->off.y;
		}
	}
	if (cast->rayh.x <= 0)
		cast->rayh.x = 0;
	if (cast->rayh.y <= 0)
		cast->rayh.y = 0;
}

void	set_verticals(t_cub3d *cube, t_cast *cast)
{
	cast->dof = 0;
	if (cast->r_angle > 90 && cast->r_angle < 270)
	{
		cast->rayv.x = (((int) cube->player.p_x >> 6) << 6) + 64;
		cast->rayv.y = ((cube->player.p_x - cast->rayv.x)
				* (tan(deg2rad(cast->r_angle)))) + cube->player.p_y;
		cast->off.x = 64;
		cast->off.y = -cast->off.x * (tan(deg2rad(cast->r_angle)));
		return ;
	}
	if ((int) cast->r_angle == 90 || (int) cast->r_angle == 270)
	{
		cast->rayv.x = cube->player.p_x;
		cast->rayv.y = cube->player.p_y;
		cast->dof = DOF;
		cast->distv = 100000;
		return ;
	}
	cast->rayv.x = (((int) cube->player.p_x >> 6) << 6) - 0.0001;
	cast->rayv.y = ((cube->player.p_x - cast->rayv.x)
			* (tan(deg2rad(cast->r_angle)))) + cube->player.p_y;
	cast->off.x = -64;
	cast->off.y = -cast->off.x * (tan(deg2rad(cast->r_angle)));
}

void	set_rayv(t_cub3d *cube, t_cast *cast)
{
	while (cast->dof < DOF)
	{
		cast->distv = 100000;
		if (cast->rayv.x / 64 >= 0 && cast->rayv.y / 64 >= 0
			&& cast->rayv.y / 64 < cube->map.height
			&& cast->rayv.x / 64 < cube->map.width
			&& (cube->map.points[(int)(cast->rayv.y / 64)]
			[(int)(cast->rayv.x / 64)] == '1'))
		{
			cast->distv = dist(cast->player, cast->rayv, cast->r_angle);
			cast->dof = DOF;
		}
		else
		{
			cast->rayv.x += cast->off.x;
			cast->rayv.y += cast->off.y;
		}
		cast->dof++;
	}
}
/*
This code appears to be part of a raycasting implementation for a 3D game or graphics application, likely using the Cube3D framework. Let's break down the main components and functions:
draw_floor_ceiling:
Draws the floor and ceiling of the 3D environment.
Uses a Digital Differential Analyzer (DDA) algorithm to draw lines.
The screen is split horizontally, with the top half being the ceiling and the bottom half the floor.
set_horizontals:
Sets up horizontal ray intersections for raycasting.
Handles different cases based on the ray angle (above or below 180 degrees).
Calculates initial ray positions and offsets for horizontal grid lines.
set_rayh:
Continues the horizontal ray casting process.
Checks for wall hits along horizontal grid lines.
Calculates the distance to horizontal intersections.
set_verticals:
Similar to set_horizontals, but for vertical ray intersections.
Handles different cases based on the ray angle (left or right of 90/270 degrees).
Calculates initial ray positions and offsets for vertical grid lines.
set_rayv:
Continues the vertical ray casting process.
Checks for wall hits along vertical grid lines.
Calculates the distance to vertical intersections.
Key points:
The code uses a 64x64 grid system for the map (evident from the bit-shifting operations).
It implements both horizontal and vertical raycasting to determine wall distances.
The DOF (Depth of Field) constant is used to limit the number of ray steps.
The code handles edge cases like rays parallel to axes (0, 90, 180, 270 degrees).
*/