/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:31:17 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:57:17 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cast_n_project(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->distt = cast->distt * cos(deg2rad(cast->angle_diff));
	cast->height.y = 64 * 400 / cast->distt;
	cast->lines.y = 400 - (cast->height.y / 2);
	cast->height.y += cast->lines.y;
	door_or_wall(cube, cast);
	cast->height.x -= 1;
	cast->lines.x -= 1;
	if (cube->m && cast->distv <= cast->disth)
		draw_line_dda(cast->player, cast->rayv, cube, 0x0055FFFF);
	else if (cube->m)
		draw_line_dda(cast->player, cast->rayh, cube, 0x0055FFFF);
	cast->r_angle += 0.075;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	else if (cast->r_angle >= 360)
		cast->r_angle -= 360;
}

void	draw_rays(t_cub3d *cube)
{
	t_cast	cast;

	initialize_cast(&cast, cube);
	while (cast.rays++ < 800)
	{
		cast.angle_diff = cube->player.p_angle - cast.r_angle;
		if (cast.angle_diff < 0)
			cast.angle_diff += 360;
		cast.player.x = cube->player.p_x;
		cast.player.y = cube->player.p_y;
		cast.dof = 0;
		set_horizontals(cube, &cast);
		set_rayh(cube, &cast);
		set_verticals(cube, &cast);
		set_rayv(cube, &cast);
		cast.player.x /= 4;
		cast.player.y /= 4;
		cast.rayv.x /= 4;
		cast.rayv.y /= 4;
		cast.rayh.x /= 4;
		cast.rayh.y /= 4;
		cast_n_project(cube, &cast);
	}
}

void	draw_map2(t_cub3d *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->m && cube->map.points[++i])
	{
		j = -1;
		while (cube->map.points[i][++j])
		{
			if (cube->map.points[i][j] == '1')
				draw_square(i, j, cube, 0x00FFFFFF);
		}
	}
}

void	render_map(t_cub3d *cube)
{
	cube->img.img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->img.addr = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	draw_floor_ceiling(cube);
	draw_rays(cube);
	draw_map2(cube);
	if (cube->m)
		draw_player(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->img.img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img.img);
}

/*
This code file contains the main rendering functions for a 3D raycasting game. Let's break down each function:
cast_n_project:
Determines the shortest distance to a wall (vertical or horizontal intersection).
Applies the fisheye correction using cosine of the angle difference.
Calculates the height of the wall slice to be drawn.
Calls door_or_wall to render the appropriate texture.
Draws minimap rays if the minimap is enabled.
draw_rays:
The main raycasting loop.
Casts 800 rays (one for each column of the screen).
For each ray:
Calculates horizontal and vertical intersections.
Determines the closest wall hit.
Calls cast_n_project to render the wall slice.
draw_map2:
Renders the 2D minimap if enabled.
Draws white squares for walls.
draw_map:
The main rendering function.
Creates a new image for the frame.
Draws the floor and ceiling.
Calls draw_rays to render the 3D view.
Calls draw_map2 to render the minimap (if enabled).
Draws the player on the minimap (if enabled).
Puts the rendered image to the window.
Key points:
The game uses a resolution of 800x800 pixels.
Raycasting is done with 800 rays, one for each vertical strip of the screen.
The minimap feature can be toggled on/off.
Textures are applied to walls based on whether the hit was vertical or horizontal.
*/