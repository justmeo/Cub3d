/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:25:00 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 15:50:24 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	pixel_put(t_cub3d *cube, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < 800 && y < 800))
	{
		dst = cube->addr + (y * cube->line_length + x * (cube->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	exit_x(t_cub3d *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_window);
	free(cube->mlx);
	return (close_free(cube), exit(0), (0));
}

int	exit_esc(int keycode, t_cub3d *cube)
{
	(void)keycode;
	mlx_destroy_window(cube->mlx, cube->mlx_window);
	free(cube->mlx);
	return (close_free(cube), exit(0), (0));
}
