

#include "cube.h"


void	validate_textures(t_cub3d *cube)
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

void	load_textures(t_cub3d *cube)
{
	validate_textures(cube);
	cube->map.i_n = load_texture(cube, cube->map.t_n, 64, 64);
	cube->map.i_s = load_texture(cube, cube->map.t_s, 64, 64);
	cube->map.i_e = load_texture(cube, cube->map.t_e, 64, 64);
	cube->map.i_w = load_texture(cube, cube->map.t_w, 64, 64);
}

void	initialize_map(t_cub3d *cube)
{
	cube->width = 800;
	cube->height = 800;
	cube->mlx = mlx_init();
	cube->mlx_window = mlx_new_window(cube->mlx, cube->width, cube->height, "");
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
	mlx_hook(cube->mlx_window, 17, 0, close_x, cube);
	mlx_hook(cube->mlx_window, 2, 1L << 0, keydown, cube);
	mlx_hook(cube->mlx_window, 3, (1L << 1), keyup, cube);
	mlx_loop_hook(cube->mlx, move, cube);
}