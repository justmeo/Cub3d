/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:33:54 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 11:42:00 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	file_check(char *string)
{
	char	*str;

	str = ft_strchr(string, '.');
	if (str && ft_strncmp(str, ".cub",5) == 0)
		return (1);
	else
	{
		printf("Error: file invalid\n");
		exit(1);
	}
	return (0);
}
