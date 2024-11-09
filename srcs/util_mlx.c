/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:25:00 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:25:01 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < 800 && y < 800))
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
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
