/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:22 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:24 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_map(t_cub3d *cube)
{
	if (cube->map.points != NULL)
		free_split(cube->map.points);
	if (cube->map.file_map != NULL)
		free_split(cube->map.file_map);
}

void	error(t_cub3d *cube, int flag)
{
	if (flag == 0)
		exit (1);
	if (flag == 1)
		ft_putstr_fd("Error: No File Name\n", 2);
	if (flag == 2)
		ft_putstr_fd("Error: Map wrong\n", 2);
	if (flag == 3)
		ft_putstr_fd("Error: Wrong number of players\n", 2);
	if (flag == 4)
		ft_putstr_fd("Error: Ceiling or Floor, wrong color\n", 2);
	if (flag == 5)
		ft_putstr_fd("Error: Textures doesn't exist\n", 2);
	if (flag == 6)
		ft_putstr_fd("Error: Map has empty line\n", 2);
	if (flag == 7)
		ft_putstr_fd("Error: Map bad\n", 2);
	if (flag == 8)
		ft_putstr_fd("Error: Empty file\n", 2);
	close_free(cube);
	exit(1);
}
