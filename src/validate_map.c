/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:59:19 by esttina           #+#    #+#             */
/*   Updated: 2026/07/12 05:55:09 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_rectangular(char **map)
{
	int	width;
	int	y;

	if (!map || !map[0])
		return (0);
	width = map_strlen(map[0]);
	y = 1;
	while (map[y] != NULL)
	{
		if (map_strlen(map[y]) != width)
			return (0);
		y++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	y;
	int	x;
	int	width;
	int	height;

	y = 1;
	x = 0;
	height = 0;
	width = map_strlen(map[0]);
	while (map[height] != NULL)
		height++;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static	int	count_char(char **map, char target)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == target)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_elements(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C'
				&& map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	if (count_char(map, 'P') != 1 || count_char(map, 'E') != 1)
		return (0);
	if (count_char(map, 'C') < 1)
		return (0);
	else
		return (1);
}
