/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 08:32:15 by esttina           #+#    #+#             */
/*   Updated: 2026/07/02 18:57:10 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x] && game->map[y][x] != '\n')
        {
            //the floor
            mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
            
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    return (0);
}