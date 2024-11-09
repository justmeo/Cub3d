/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map_parscing3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:26 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:25:58 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//to be changed
void	check_updown(t_cub3d *cub3d, int row, int colom)
{
	int	vert;

	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert--;
		if (vert < 0 || colom >= (int)ft_strlen(cub3d->map.points[vert])
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error(cub3d, 2);
	}
	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert++;
		if (vert >= cub3d->map.height
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error(cub3d, 2);
	}
}

//to be changed
int	check_leftright(t_cub3d *cub3d, int row, int colom)
{
	int	hor;

	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor--;
		if (hor < 0 || valid_letter(cub3d->map.points[row][hor]) == 1)
			error(cub3d, 2);
	}
	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor++;
		if (hor >= cub3d->map.width
			|| valid_letter(cub3d->map.points[row][hor]) == 1)
			error(cub3d, 2);
	}
	return (1);
}

//to be changed
void	door_or_wall(t_cub3d *cube, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		wall_text_v(cast->height, cast->lines, cube, cast);
	else
		render_horizontal_wall_texture(cast->height, cast->lines, cube, cast);
}

//to be changed
void	valid_line(char *string, t_cub3d *cube, char *freeme)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (valid_letter(string[i]))
		{
			free (freeme);
			error(cube, 2);
		}
		i++;
	}
}

//to be changed
void	mapread(t_cub3d *cub3d, int start)
{
	int		c;
	char	*str;

	c = start;
	str = ft_strdup(cub3d->map.file_map[c]);
	while (cub3d->map.file_map[c])
	{
		valid_line(cub3d->map.file_map[c], cub3d, str);
		str = free_extra_strings(str, "\n", 1);
		str = free_extra_strings(str, cub3d->map.file_map[c], 1);
		c++;
	}
	str = ft_strtrim_free(str, "\n");
	cub3d->map.points = ft_split(str, '\n');
	free(str);
	check_player_exist(cub3d);
	map_size(cub3d);
	if (cub3d->map.height > 56
		|| cub3d->map.height <= 2 || cub3d->map.width <= 2)
		error(cub3d, 7);
	map_checker(cub3d);
	player_info(cub3d);
}
