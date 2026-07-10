/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:56:55 by esttina           #+#    #+#             */
/*   Updated: 2026/07/10 18:37:53 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(char **map, int rows)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	scan_unreachable(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

static void	find_start(char **map, int *p_x, int *p_y)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				*p_x = x;
				*p_y = y;
			}
			x++;
		}
		y++;
	}
}

int	check_path(char **map)
{
	char	**duplicate;
	int		y;
	int		p_x;
	int		p_y;

	y = 0;
	while (map[y])
		y++;
	duplicate = duplicate_map(map, y);
	if (!duplicate)
		return (0);
	find_start(duplicate, &p_x, &p_y);
	fill(duplicate, p_x, p_y);
	if (scan_unreachable(duplicate) == 1)
	{
		free_map(duplicate);
		return (0);
	}
	free_map(duplicate);
	return (1);
}
