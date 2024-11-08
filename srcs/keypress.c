/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:59:52 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 19:35:02 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

int	keyup(int keycode, t_cub3d *cube)
{
	if (keycode == KEY_ESCAPE)
		return (close_esc(keycode, cube));
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

/*
This code file handles keyboard input for a 3D raycasting game, allowing the player to move and rotate within the game world. Let's break down each function:
change_angle:
Adjusts the player's viewing angle based on left or right directional input.
Increments or decrements the angle by 1 degree.
Ensures the angle wraps around correctly between 0 and 360 degrees.
change_position:
Calculates the player's movement vector (p_dx, p_dy) based on their current angle.
If the "shift" key is pressed, the movement speed is increased (multiplied by 3).
Uses trigonometric functions to determine movement direction based on the player's angle.
keydown:
Sets directional flags when keys are pressed.
Recognizes keys for forward (W), left (A), backward (S), right (D), rotate left (LEFT), rotate right (RIGHT), and sprint (SHIFT).
keyup:
Resets directional flags when keys are released.
Includes handling for the escape key (ESC) to close the game.
Key Points:
Direction Flags: The game uses boolean flags to track which keys are currently pressed, influencing player movement and rotation.
Trigonometry: Movement calculations rely on converting angles to radians for use with cos and sin.
Speed Control: The "shift" key increases movement speed, simulating a sprint feature.
Angle Wrapping: Ensures smooth rotation by wrapping angles between 0 and 360 degrees.
*/