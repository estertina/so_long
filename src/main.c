/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:42:24 by esttina           #+#    #+#             */
/*   Updated: 2026/07/12 05:55:41 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	else
		return (1);
}

static int	check_map_validity(char **map)
{
	if (check_rectangular(map) == 0)
	{
		ft_putstr_fd("Error\nThe map is not a valid rectangle.\n", 2);
		return (0);
	}
	if (check_walls(map) == 0)
	{
		ft_putstr_fd("Error\nThe map is not surrounded by walls.\n", 2);
		return (0);
	}
	if (check_elements(map) == 0)
	{
		ft_putstr_fd("Error\nInvalid map elements.\n", 2);
		return (0);
	}
	if (check_path(map) == 0)
	{
		ft_putstr_fd("Error\nThere is no valid path\
			 to the exit or coins.\n", 2);
		return (0);
	}
	return (1);
}

static void	init_and_run_game(t_game *game, char **map)
{
	int	rows;

	game->map = map;
	player_position(game);
	game->mlx = mlx_init();
	game->map_w = map_strlen(map[0]) * TILE_SIZE;
	rows = 0;
	while (map[rows] != NULL)
		rows++;
	game->map_h = rows * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	init_images(game);
	render_map(game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_hook (game->win, 2, (1L << 0), key_hook, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	char	**map;
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ac != 2 || !check_extension(av[1]))
	{
		ft_putstr_fd("Error\nInvalid map file or extension.\n", 2);
		return (1);
	}
	map = read_map_file(av[1]);
	if (!map)
	{
		ft_putstr_fd("Error\nCannot open file.\n", 2);
		return (1);
	}
	if (check_map_validity(map) == 0)
	{
		free_map(map);
		return (1);
	}
	ft_putstr_fd("Success! We opened and validated the file.\n", 2);
	init_and_run_game(&game, map);
	return (0);
}
