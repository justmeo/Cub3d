/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:24:51 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/11/09 15:24:53 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	line_counter(char **dp)
{
	int	line_counter;

	line_counter = 0;
	while (dp[line_counter] != NULL)
		line_counter++;
	return (line_counter);
}

double	deg_to_rad(double deg)
{
	return (deg * (PI_CONST / 180.0));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_digit(char *string)
{
	int	c;

	c = 0;
	while (string[c])
	{
		if (!ft_isdigit(string[c]))
		{
			free(string);
			return (0);
		}
		c++;
	}
	free(string);
	return (1);
}

int	valid_letter(char letter)
{
	if (letter == '0' || letter == 'N' || letter == 'S' || letter == 'E'
		|| letter == 'W' || letter == ' ' || letter == '1')
		return (0);
	return (1);
}
