/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:03:16 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 12:45:03 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	dda(t_point x1, t_point x2, t_cub3d *cube, int color)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
	{
		steps = fabsf(x2.x - x1.x);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	else
	{
		steps = fabsf(x2.y - x1.y);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	i = 1;
	while (i++ <= steps)
		pixel_put(&cube->img, x1.x + (increase_x * (i - 1)),
			x1.y + (increase_y * (i - 1)),
			color);
}

void	wall_text_v(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;
	float	increase_t;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
		steps = fabsf(x2.x - x1.x);
	else
		steps = fabsf(x2.y - x1.y);
	increase_x = (x2.x - x1.x) / steps;
	increase_y = (x2.y - x1.y) / steps;
	increase_t = 64 / steps;
	i = -1;
	while (++i < steps)
	{
		if (v_angle(cast) && v_condition(x1, increase_x, increase_y, i))
			pixel_put(&cube->img, x1.x + (increase_x * i),
				x1.y + (increase_y * i), cube->map.i_e[
				(int)fabsf(increase_t * i)][(int)(cast->rayv.y * 4) % 64]);
		else
			pixel_put(&cube->img, x1.x + (increase_x * i),
				x1.y + (increase_y * i), cube->map.i_w[
				(int)fabsf(increase_t * i)][(int)(cast->rayv.y * 4) % 64]);
	}
}

void	wall_text_h(t_point x1, t_point x2, t_cub3d *cube, t_cast *cast)
{
	t_dda	h;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
		h.s = fabsf(x2.x - x1.x);
	else
		h.s = fabsf(x2.y - x1.y);
	h.x = (x2.x - x1.x) / h.s;
	h.y = (x2.y - x1.y) / h.s;
	h.t = 64 / h.s;
	h.i = 0;
	while (h.i++ <= h.s)
	{
		if (cast->r_angle > 0 && cast->r_angle < 180)
			pixel_put(&cube->img, x1.x + (h.x * (h.i - 1)),
				x1.y + (h.y * (h.i - 1)), cube->map.i_s[
				(int)fabsf(h.t * (h.i - 1))][(int)(cast->rayh.x * 4) % 64]);
		else
			pixel_put(&cube->img, x1.x + (h.x * (h.i - 1)),
				x1.y + (h.y * (h.i - 1)), cube->map.i_n[
				(int)fabsf(h.t * (h.i - 1))]
			[(int)(cast->rayh.x * 4) % 64]);
	}
}

/*
Answer
This code implements the Digital Differential Analyzer (DDA) algorithm for line drawing and texture mapping in a 3D raycasting engine. Let's break down the three main functions:
dda function:
Implements the basic DDA algorithm for drawing lines.
Calculates the number of steps based on the larger difference (x or y).
Draws the line pixel by pixel using pixel_put.
wall_text_v function:
Implements texture mapping for vertical walls.
Similar to dda, but incorporates texture sampling.
Uses the v_angle and v_condition helper functions to determine which texture to use (East or West) and if the pixel should be drawn.
Samples the texture based on the vertical position of the ray hit (rayv.y).
wall_text_h function:
Implements texture mapping for horizontal walls.
Uses a struct t_dda to store DDA variables for cleaner code.
Determines whether to use North or South texture based on the ray angle.
Samples the texture based on the horizontal position of the ray hit (rayh.x).
Key points:
The code assumes a 64x64 texture size.
Texture sampling is done with a 4x multiplier on ray hit positions, likely for higher resolution textures.
The functions handle both the drawing of lines and the application of textures in the same loop for efficiency.
*/