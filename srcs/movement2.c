/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:23:40 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/11 19:51:15 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// to be changed
void	change_angle(t_cub3d *cube)
{
	if (cube->left)
		cube->player_angle += 1;
	if (cube->right)
		cube->player_angle -= 1;
	if (cube->player_angle < 0)
		cube->player_angle = 360;
	else if (cube->player_angle >= 360)
		cube->player_angle = 0;
}

// to be changed
int	keydown(int keycode, t_cub3d *cube)
{
	if (keycode == W)
		cube->movement_w = true;
	else if (keycode == A)
		cube->movement_a = true;
	else if (keycode == S)
		cube->movement_s = true;
	else if (keycode == D)
		cube->movement_d = true;
	else if (keycode == KEY_LEFT_ARROW)
		cube->left = true;
	else if (keycode == KEY_RIGHT_ARROW)
		cube->right = true;
	return (0);
}

// to be changed
int	keyup(int keycode, t_cub3d *cube)
{
	if (keycode == KEY_ESCAPE)
		return (exit_esc(keycode, cube));
	else if (keycode == W)
		cube->movement_w = false;
	else if (keycode == A)
		cube->movement_a = false;
	else if (keycode == S)
		cube->movement_s = false;
	else if (keycode == D)
		cube->movement_d = false;
	else if (keycode == KEY_LEFT_ARROW)
		cube->left = false;
	else if (keycode == KEY_RIGHT_ARROW)
		cube->right = false;
	return (0);
}
