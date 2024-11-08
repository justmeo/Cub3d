/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:31:36 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 13:49:55 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

unsigned int	**t_ext(t_cub3d *cube, char *map, int x, int y)
{
	int				width;
	int				height;
	int				pos;
	char			*name;
	unsigned int	**num;

	cube->img.img = mlx_xpm_file_to_image(cube->mlx, map, &width, &height);
	if (cube->img.img == NULL)
		error(cube, 5);
	name = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	num = ft_calloc(65, sizeof(unsigned int *));
	y = 64;
	while (y > -1)
	{
		x = 64;
		num[y] = ft_calloc(65, sizeof(unsigned int));
		while (x > -1)
		{
			pos = (y * cube->img.line_length + x * (cube->img.bpp / 8));
			num[y][x] = *(unsigned int *)&name[pos];
			x--;
		}
		y--;
	}
	mlx_destroy_image(cube->mlx, cube->img.img);
	return (num);
}

void	check_text(t_cub3d *cube)
{
	if (access(cube->map.t_n, F_OK | R_OK) == -1
		|| access(cube->map.t_s, F_OK | R_OK) == -1
		|| access(cube->map.t_w, F_OK | R_OK) == -1
		|| access(cube->map.t_e, F_OK | R_OK) == -1)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_window);
		free(cube->mlx);
		error(cube, 5);
	}
}

void	get_text(t_cub3d *cube)
{
	check_text(cube);
	cube->map.i_n = t_ext(cube, cube->map.t_n, 64, 64);
	cube->map.i_s = t_ext(cube, cube->map.t_s, 64, 64);
	cube->map.i_e = t_ext(cube, cube->map.t_e, 64, 64);
	cube->map.i_w = t_ext(cube, cube->map.t_w, 64, 64);
}

void	create_map(t_cub3d *cube)
{
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height, "");
	get_text(cube);
	draw_map(cube);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	if (argc != 2 || file_check(argv[1]) != 1)
	{
		ft_putstr_fd("Error: WRONG AMOUNT OF ARGUMENTS", 2);
		exit(1);
	}
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		error(&cube, 0);
	init(&cube);
	openmap(&cube, argv);
	set_booleans(&cube);
	create_map(&cube);
	mlx_hook(cube.mlx_window, 17, 0, close_x, &cube);
	mlx_hook(cube.mlx_window, 2, 1L << 0, keydown, &cube);
	mlx_hook(cube.mlx_window, 3, (1L << 1), keyup, &cube);
	mlx_loop_hook(cube.mlx, move, &cube);
	mlx_loop(cube.mlx);
}


/*
This code appears to be the main implementation file for a 3D game or graphics application, likely a Wolfenstein 3D-style game using the MLX library. Let's break down the main components:
t_ext function:
Loads texture images from XPM files.
Converts the image data into a 2D array of unsigned integers.
This allows for easier texture mapping in the rendering process.
check_text function:
Verifies that all required texture files exist and are readable.
If any texture is missing or unreadable, it terminates the program with an error.
get_text function:
Calls check_text to verify textures.
Loads all four directional textures (North, South, East, West) using t_ext.
create_map function:
Initializes the MLX window and context.
Sets up the game window with dimensions 800x800.
Loads textures and draws the initial map.
main function:
Checks command-line arguments and file accessibility.
Initializes the game structure.
Opens and processes the map file.
Sets up event hooks for:
Window closing (X button)
Key press and release events
Continuous movement updates
Starts the MLX event loop.
Key points:
The program expects a single command-line argument, which should be the path to a valid map file.
It uses MLX (MiniLibX) for graphics rendering and event handling.
Textures are loaded from XPM files and converted to a format suitable for quick access during rendering.
The game window is set to 800x800 pixels.
The code implements basic error handling for file access and texture loading.
*/