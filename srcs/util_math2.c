/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:56 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:24:58 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

float	dist(t_point player, t_point ray, float angle)
{
	(void) angle;
	return (sqrt(((ray.x - player.x) * (ray.x - player.x))
			+ ((ray.y - player.y) * (ray.y - player.y))
		));
}

//to be changed
bool	is_wall(t_cub3d *cube, t_point ray)
{
	if (cube->map.points[(int)(ray.y / 16)][(int)(ray.x / 16)] == '1')
		return (true);
	return (false);
}
