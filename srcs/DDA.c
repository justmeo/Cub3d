/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:16 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 14:03:27 by fmaqdasi         ###   ########.fr       */
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
		pixel_put(&cube->img, start.x + (increase_x * (i - 1)),
			start.y + (increase_y * (i - 1)),
			color);
}

bool	is_ray_facing_left(t_cast *cast)
{
	if (cast->r_angle > 90 && cast->r_angle < 270)
		return (true);
	return (false);
}

void	wall_text_v(t_point start, t_point end, t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;
	float	increase_t;

	if (fabsf(end.x - start.x) > fabsf(end.y - start.y))
		steps = fabsf(end.x - start.x);
	else
		steps = fabsf(end.y - start.y);
	increase_x = (end.x - start.x) / steps;
	increase_y = (end.y - start.y) / steps;
	increase_t = 64 / steps;
	i = -1;
	while (++i < steps)
	{
		if (is_ray_facing_left(cast) && is_within_vertical_bounds(start, increase_x, increase_y, i))
			pixel_put(&cube->img, start.x + (increase_x * i),
				start.y + (increase_y * i), cube->map.i_e[
				(int)fabsf(increase_t * i)][(int)(cast->rayv.y * 4) % 64]);
		else
			pixel_put(&cube->img, start.x + (increase_x * i),
				start.y + (increase_y * i), cube->map.i_w[
				(int)fabsf(increase_t * i)][(int)(cast->rayv.y * 4) % 64]);
	}
}

void	render_horizontal_wall_texture(t_point start, t_point end, t_cub3d *cube, t_cast *cast)
{
	t_dda	h;

	if (fabsf(end.x - start.x) > fabsf(end.y - start.y))
		h.s = fabsf(end.x - start.x);
	else
		h.s = fabsf(end.y - start.y);

	h.x = (end.x - start.x) / h.s;
	h.y = (end.y - start.y) / h.s;
	h.t = 64 / h.s;
	h.i = 0;

	while (h.i++ <= h.s)
	{
		if (cast->r_angle > 0 && cast->r_angle < 180)
			pixel_put(&cube->img, start.x + (h.x * (h.i - 1)),
				start.y + (h.y * (h.i - 1)), 
				cube->map.i_s[(int)fabsf(h.t * (h.i - 1))]
				[(int)(cast->rayh.x * 4) % 64]);
		else
			pixel_put(&cube->img, start.x + (h.x * (h.i - 1)),
				start.y + (h.y * (h.i - 1)), 
				cube->map.i_n[(int)fabsf(h.t * (h.i - 1))]
				[(int)(cast->rayh.x * 4) % 64]);
	}
}

bool	is_within_vertical_bounds(t_point start, float increment_x, float increment_y, int step)
{
	if (start.x + (increment_x * step) >= 0 && start.x + (increment_x * step) < 800
		&& start.y + (increment_y * step) >= 0 && start.y + (increment_y * step) < 800)
		return (true);
	return (false);
}

