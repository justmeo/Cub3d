/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:12:15 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:44:07 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	v_condition(t_point x1, float increase_x, float increase_y, int i)
{
	if (x1.x + (increase_x * i) >= 0 && x1.x
		+ (increase_x * i) < 800 && x1.y + (increase_y * i) >= 0
		&& x1.y + (increase_y * i) < 800)
		return (true);
	return (false);
}

bool	v_angle(t_cast *cast)
{
	if (cast->r_angle > 90 && cast->r_angle < 270)
		return (true);
	return (false);
}

/*
This code snippet contains helper functions for the Digital Differential Analyzer (DDA) algorithm, which is commonly used in computer graphics for line drawing and raycasting. Let's break down the two functions:
v_condition function:
Purpose: Checks if a point is within the bounds of the screen or drawing area.
Parameters:
x1: The starting point.
increase_x and increase_y: The increments in x and y directions.
i: The current step or iteration.
Function:
Calculates the new x and y coordinates based on the starting point and increments.
Checks if these new coordinates are within the bounds (0 to 799 for both x and y).
Returns:
true if the point is within bounds.
false if the point is out of bounds.
v_angle function:
Purpose: Determines if a ray is facing left (west) in the game world.
Parameters:
cast: A pointer to a structure containing ray casting information.
Function:
Checks if the ray angle is between 90 and 270 degrees.
Returns:
true if the angle is between 90 and 270 degrees (facing left/west).
false otherwise.
Key points:
The screen or drawing area is assumed to be 800x800 pixels (0 to 799 in both dimensions).
These functions are likely used in the main raycasting loop to optimize calculations and handle edge cases.
*/