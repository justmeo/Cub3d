/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_main2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:00 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:42:56 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// to be changed
void	openmap(t_cub3d *cub3d, char *argv[])
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(cub3d, 1);
	str = readfile(fd);
	if (!str)
		error(cub3d, 8);
	cub3d->map.file_map = ft_split(str, '\n');
	free(str);
	texture_parse(cub3d);
	cub3d->player_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player_y = cub3d->map.p_row * 64 + 32;
	cub3d->player_dx = cos(cub3d->player_angle) * 1;
	cub3d->player_dy = sin(cub3d->player_angle) * 1;
}
