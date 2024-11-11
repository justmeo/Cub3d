/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:22:47 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 15:53:05 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	load_texture_extra(unsigned int **pixel_array, char *image_data,
		t_cub3d *cube, int y)
{
	int	pixel_position;
	int	x;

	x = 64;
	pixel_array[y] = ft_calloc(65, sizeof(unsigned int));
	while (x >= 0)
	{
		pixel_position = (y * cube->line_length + x * (cube->bpp / 8));
		pixel_array[y][x] = *(unsigned int *)&image_data[pixel_position];
		x--;
	}
}

unsigned int	**load_texture(t_cub3d *cube, char *texture_path, int x, int y)
{
	int				width;
	int				height;
	char			*image_data;
	unsigned int	**pixel_array;

	(void)x;
	cube->img = mlx_xpm_file_to_image(cube->mlx, texture_path, &width,
			&height);
	if (cube->img == NULL)
		error(cube, 5);
	image_data = mlx_get_data_addr(cube->img, &cube->bpp,
			&cube->line_length, &cube->endian);
	pixel_array = ft_calloc(65, sizeof(unsigned int *));
	y = 64;
	while (y >= 0)
	{
		load_texture_extra(pixel_array, image_data, cube, y);
		y--;
	}
	mlx_destroy_image(cube->mlx, cube->img);
	return (pixel_array);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	check_arguments(argc, argv[1], &cube);
	init(&cube);
	openmap(&cube, argv);
	initialize_map(&cube);
	setup_hooks(&cube);
	mlx_loop(cube.mlx);
}
