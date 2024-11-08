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

unsigned int	**load_texture(t_cub3d *cube, char *texture_path, int x, int y)
{
	int				width;
	int				height;
	int				pixel_position;
	char			*image_data;
	unsigned int	**pixel_array;

	cube->img.img = mlx_xpm_file_to_image(cube->mlx, texture_path, &width, &height);
	if (cube->img.img == NULL)
		error(cube, 5);
	image_data = mlx_get_data_addr(cube->img.img, &cube->img.bpp,
			&cube->img.line_length, &cube->img.endian);
	pixel_array = ft_calloc(65, sizeof(unsigned int *));
	y = 64;
	while (y >= 0)
	{
		x = 64;
		pixel_array[y] = ft_calloc(65, sizeof(unsigned int));
		while (x >= 0)
		{
			pixel_position = (y * cube->img.line_length + x * (cube->img.bpp / 8));
			pixel_array[y][x] = *(unsigned int *)&image_data[pixel_position];
			x--;
		}
		y--;
	}
	mlx_destroy_image(cube->mlx, cube->img.img);
	return (pixel_array);
}


int	main(int argc, char *argv[])
{
	t_cub3d	cube;

	check_arguments(argc, argv[1], &cube);
	init(&cube);
	openmap(&cube, argv);
	set_booleans(&cube);
	initialize_map(&cube);
	setup_hooks(&cube);
	mlx_loop(cube.mlx);
}

