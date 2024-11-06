/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:33:54 by jadithya          #+#    #+#             */
/*   Updated: 2024/11/06 12:59:33 by fmaqdasi         ###   ########.fr       */
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

/*
This code file contains a single function file_check that validates the file extension of the map file for a 3D raycasting game. Let's break down this function:
file_check:
Takes a string (presumably a filename) as input.
Uses ft_strchr to find the last occurrence of a dot (.) in the filename.
If a dot is found, it checks if the extension is exactly ".cub" using ft_strncmp.
Returns 1 if the file has a ".cub" extension.
If the extension is not ".cub", it prints an error message and exits the program.
Key points:
The function ensures that the map file has the correct ".cub" extension.
It uses custom string manipulation functions (ft_strchr, ft_strncmp) instead of standard library functions, which is common in educational projects like those at 42 schools.
The function exits the program immediately if the file extension is invalid, providing a simple error message.
Potential improvements or considerations:
Instead of exiting the program directly, consider returning an error code and handling the exit in the main function. This would allow for more graceful error handling and potential cleanup operations.
The error message is printed to stdout (using printf). It's generally better to print error messages to stderr using fprintf(stderr, ...) or a similar function.
The function could be more robust by checking if the filename is NULL or empty before processing.
Consider making the extension check case-insensitive to allow for variations like ".CUB" or ".Cub".
The ft_strncmp is checking 5 characters, which includes the null terminator. It might be clearer to explicitly check for 4 characters plus the null terminator separately.
*/