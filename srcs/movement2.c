/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:40 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:25:39 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//to be changed
void	change_angle(t_cub3d *cube)
{
	if (cube->dir.left)
		cube->player.p_angle += 1;
	if (cube->dir.right)
		cube->player.p_angle -= 1;
	if (cube->player.p_angle < 0)
		cube->player.p_angle = 360;
	else if (cube->player.p_angle >= 360)
		cube->player.p_angle = 0;
}

//to be changed
int	keydown(int keycode, t_cub3d *cube)
{
	if (keycode == W)
		cube->dir.w = true;
	else if (keycode == A)
		cube->dir.a = true;
	else if (keycode == S)
		cube->dir.s = true;
	else if (keycode == D)
		cube->dir.d = true;
	else if (keycode == KEY_LEFT_ARROW)
		cube->dir.left = true;
	else if (keycode == KEY_RIGHT_ARROW)
		cube->dir.right = true;
	return (0);
}

//to be changed
int	keyup(int keycode, t_cub3d *cube)
{
	if (keycode == KEY_ESCAPE)
		return (exit_esc(keycode, cube));
	else if (keycode == W)
		cube->dir.w = false;
	else if (keycode == A)
		cube->dir.a = false;
	else if (keycode == S)
		cube->dir.s = false;
	else if (keycode == D)
		cube->dir.d = false;
	else if (keycode == KEY_LEFT_ARROW)
		cube->dir.left = false;
	else if (keycode == KEY_RIGHT_ARROW)
		cube->dir.right = false;
	return (0);
}
