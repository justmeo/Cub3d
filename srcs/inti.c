/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:29 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:31 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//to be changed
char	*readfile(int fd)
{
	char	*ntext;
	char	*text;
	bool	flag;

	text = get_next_line(fd);
	ntext = get_next_line(fd);
	flag = false;
	while (ntext != NULL)
	{
		text = free_extra_strings(text, ntext, 0);
		ntext = get_next_line(fd);
		if (flag && ntext && ft_strlen(ntext) == 1)
		{
			free(ntext);
			ntext = ft_strdup("00000");
			continue ;
		}
		if (ntext && ft_strncmp("NO", ntext, 2) && ft_strncmp("SO", ntext, 2)
			&& ft_strncmp("EA", ntext, 2) && ft_strncmp("WE", ntext, 2)
			&& ft_strncmp("F", ntext, 1) && ft_strncmp("C", ntext, 1)
			&& ft_strlen(ntext) > 1)
			flag = true;
	}
	return (text);
}

//to be changed
void	initialize_cast(t_cast *cast, t_cub3d *cube)
{
	cast->rays = 0;
	cast->r_angle = cube->player.p_angle - 30;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	cast->lines.x = 800;
	cast->lines.y = 0;
	cast->height.x = 800;
}

//to be changed
void	init(t_cub3d *cube)
{
	cube->map.points = NULL;
	cube->map.file_map = NULL;
	cube->map.t_n = NULL;
	cube->map.t_s = NULL;
	cube->map.t_e = NULL;
	cube->map.t_w = NULL;
	cube->map.i_n = NULL;
	cube->map.i_s = NULL;
	cube->map.i_e = NULL;
	cube->map.i_w = NULL;
}
