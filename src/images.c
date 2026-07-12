/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 03:16:19 by esttina           #+#    #+#             */
/*   Updated: 2026/07/12 05:54:09 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor || !game->img_player)
	{
		ft_putstr_fd("Error: Could not load XPM file\n", 2);
		exit(1);
	}
	if (!game->img_collectible || !game->img_exit)
	{
		ft_putstr_fd("Error: Could not load XPM file\n", 2);
		exit(1);
	}
}
