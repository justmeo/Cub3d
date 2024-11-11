/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/11/09 15:23:53 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:53 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	load_textures(t_cub3d *cube)
{
	if (access(cube->map.file_n, F_OK | R_OK) == -1 || access(cube->map.file_s,
			F_OK | R_OK) == -1 || access(cube->map.file_w, F_OK | R_OK) == -1
		|| access(cube->map.file_e, F_OK | R_OK) == -1)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_window);
		free(cube->mlx);
		error(cube, 5);
	}
	cube->map.texture_n = load_texture(cube, cube->map.file_n, 64, 64);
	cube->map.texture_s = load_texture(cube, cube->map.file_s, 64, 64);
	cube->map.texture_e = load_texture(cube, cube->map.file_e, 64, 64);
	cube->map.texture_w = load_texture(cube, cube->map.file_w, 64, 64);
}

void	initialize_map(t_cub3d *cube)
{
	cube->movement_w = false;
	cube->movement_s = false;
	cube->movement_a = false;
	cube->movement_d = false;
	cube->left = false;
	cube->right = false;
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height,
			"");
	load_textures(cube);
	render_map(cube);
}

void	check_arguments(int argc, char *filename, t_cub3d *cube)
{
	if (argc != 2 || file_check(filename) != 1)
	{
		ft_putstr_fd("Error: INVALID NUMBER OF ARGUMENTS PROVIDED", 2);
		exit(1);
	}
	if (access(filename, F_OK) == -1 || access(filename, R_OK) == -1)
		error(cube, 0);
}

void	setup_hooks(t_cub3d *cube)
{
	mlx_hook(cube->mlx_window, 17, 0, exit_x, cube);
	mlx_hook(cube->mlx_window, 2, 1L << 0, keydown, cube);
	mlx_hook(cube->mlx_window, 3, (1L << 1), keyup, cube);
	mlx_loop_hook(cube->mlx, move, cube);
}

int	file_check(char *string)
{
	char	*str;

	str = ft_strchr(string, '.');
	if (str && ft_strncmp(str, ".cub", 5) == 0)
		return (1);
	else
	{
		printf("Error: file invalid\n");
		exit(1);
	}
	return (0);
}
