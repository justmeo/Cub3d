/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:35 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:48:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// to be changed
void	cast_n_project(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->distt = cast->distt * cos(deg_to_rad(cast->angle_diff));
	cast->height.y = 64 * 400 / cast->distt;
	cast->lines.y = 400 - (cast->height.y / 2);
	cast->height.y += cast->lines.y;
	door_or_wall(cube, cast);
	cast->height.x -= 1;
	cast->lines.x -= 1;
	cast->r_angle += 0.075;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	else if (cast->r_angle >= 360)
		cast->r_angle -= 360;
}

// to be changed
void	draw_rays(t_cub3d *cube)
{
	t_cast	cast;

	initialize_cast(&cast, cube);
	while (cast.rays++ < 800)
	{
		cast.angle_diff = cube->player_angle - cast.r_angle;
		if (cast.angle_diff < 0)
			cast.angle_diff += 360;
		cast.player.x = cube->player_x;
		cast.player.y = cube->player_y;
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

// to be changed
void	render_map(t_cub3d *cube)
{
	cube->img = mlx_new_image(cube->mlx, cube->width, cube->height);
	cube->addr = mlx_get_data_addr(cube->img, &cube->bpp, &cube->line_length,
			&cube->endian);
	draw_floor_ceiling(cube);
	draw_rays(cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_window, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);
}

// to be changed
void	draw_square(int i, int j, t_cub3d *cube, int color)
{
	int	a;
	int	b;
	int	hold;

	a = (i + 1) * 16;
	b = (j + 1) * 16;
	i *= 16;
	hold = j * 16;
	while (i < a)
	{
		j = hold;
		while (j < b)
		{
			if (i == a - 1 || j == b - 1)
				pixel_put(cube, j, i, 0x00DDDDDD);
			else
				pixel_put(cube, j, i, color);
			j++;
		}
		i++;
	}
}

// to be changed
void	draw_angle(t_cub3d *cube3d)
{
	float	dy;
	float	dx;
	float	c;
	int		i;

	dx = (cube3d->player_x - cube3d->player_dx);
	dy = (cube3d->player_y - cube3d->player_dy);
	if (fabs(dx) > fabs(dy))
		c = fabs(dx);
	else
		c = fabs(dy);
	i = 0;
	(void)i;
	dx /= c;
	dy /= c;
	while (i <= c)
	{
		pixel_put(cube3d, cube3d->player_dx / 4, cube3d->player_dy / 4,
			0x00FF0000);
		cube3d->player_dy += dy;
		cube3d->player_dx += dx;
		i++;
	}
}
