/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:52 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 13:00:15 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_x(t_cub3d *cube)
{
	mlx_destroy_window(cube->mlx, cube->mlx_window);
	free(cube->mlx);
	close_free(cube);
	exit(0);
	return (0);
}

int	close_esc(int keycode, t_cub3d *cube)
{
	(void) keycode;
	mlx_destroy_window(cube->mlx, cube->mlx_window);
	free(cube->mlx);
	close_free(cube);
	exit(0);
	return (0);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < 800 && y < 800))
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

/*
This code file contains functions for window management and pixel drawing in a 3D raycasting game. Let's break down each function:
close_x:
Handles the closing of the game window when the user clicks the close (X) button.
Destroys the window, frees the MLX (MiniLibX) instance.
Calls close_free to clean up other resources.
Exits the program.
close_esc:
Similar to close_x, but triggered by pressing the ESC key.
The keycode parameter is ignored (void cast).
Performs the same cleanup and exit process as close_x.
pixel_put:
A utility function to set the color of a specific pixel in the image buffer.
Checks if the pixel coordinates are within the bounds of the window (0 to 799 for both x and y).
Calculates the memory address for the pixel and sets its color.
Key points:
The code uses the MLX library for window management and graphics.
Both closing functions (for X button and ESC key) perform the same cleanup operations.
The pixel_put function includes bounds checking to prevent writing outside the image buffer.
The window size is assumed to be 800x800 pixels.
Potential improvements or considerations:
The magic number 800 for window dimensions could be replaced with a constant or configuration variable.
Consider combining close_x and close_esc into a single function, as they perform the same operations.
Error handling could be added for MLX functions (e.g., checking if mlx_destroy_window succeeds).
The pixel_put function could be optimized for performance, especially if it's called frequently.
Consider adding a confirmation dialog before closing the game, especially if there's unsaved progress.
*/