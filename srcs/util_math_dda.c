/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math_dda.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:47 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:48:30 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_line_dda(t_point start, t_point end, t_cub3d *cube, int color)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;

	if (fabsf(end.x - start.x) > fabsf(end.y - start.y))
	{
		steps = fabsf(end.x - start.x);
		increase_x = (end.x - start.x) / steps;
		increase_y = (end.y - start.y) / steps;
	}
	else
	{
		steps = fabsf(end.y - start.y);
		increase_x = (end.x - start.x) / steps;
		increase_y = (end.y - start.y) / steps;
	}
	i = 1;
	while (i++ <= steps)
		pixel_put(cube, start.x + (increase_x * (i - 1)), start.y + (increase_y
				* (i - 1)), color);
}

bool	is_ray_facing_left(t_cast *cast)
{
	if (cast->r_angle > 90 && cast->r_angle < 270)
		return (true);
	return (false);
}

//increase x
//increase y
//increase t
void	wall_text_v(t_point start, t_point end, t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase[3];

	if (fabsf(end.x - start.x) > fabsf(end.y - start.y))
		steps = fabsf(end.x - start.x);
	else
		steps = fabsf(end.y - start.y);
	increase[0] = (end.x - start.x) / steps;
	increase[1] = (end.y - start.y) / steps;
	increase[2] = 64 / steps;
	i = -1;
	while (++i < steps)
	{
		if (is_ray_facing_left(cast) && is_within_vertical_bounds(start,
				increase[0], increase[1], i))
			pixel_put(cube, start.x + (increase[0] * i), start.y + (increase[1]
					* i), cube->map.i_e[(int)fabsf(increase[2]
					* i)][(int)(cast->rayv.y * 4) % 64]);
		else
			pixel_put(cube, start.x + (increase[0] * i), start.y + (increase[1]
					* i), cube->map.i_w[(int)fabsf(increase[2]
					* i)][(int)(cast->rayv.y * 4) % 64]);
	}
}

void	render_horizontal_wall_texture(t_point start, t_point end,
		t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	s;
	float	t;
	float	y;
	float	x;

	if (fabsf(end.x - start.x) > fabsf(end.y - start.y))
		s = fabsf(end.x - start.x);
	else
		s = fabsf(end.y - start.y);
	x = (end.x - start.x) / s;
	y = (end.y - start.y) / s;
	t = 64 / s;
	i = 0;
	while (i++ <= s)
	{
		if (cast->r_angle > 0 && cast->r_angle < 180)
			pixel_put(cube, start.x + (x * (i - 1)), start.y + (y * (i - 1)),
				cube->map.i_s[(int)fabsf(t * (i - 1))][(int)(cast->rayh.x * 4)
				% 64]);
		else
			pixel_put(cube, start.x + (x * (i - 1)), start.y + (y * (i - 1)),
				cube->map.i_n[(int)fabsf(t * (i - 1))][(int)(cast->rayh.x * 4)
				% 64]);
	}
}

bool	is_within_vertical_bounds(t_point start, float increment_x,
		float increment_y, int step)
{
	if (start.x + (increment_x * step) >= 0 && start.x + (increment_x
			* step) < 800 && start.y + (increment_y * step) >= 0 && start.y
		+ (increment_y * step) < 800)
		return (true);
	return (false);
}
