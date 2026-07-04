/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:03:29 by esttina           #+#    #+#             */
/*   Updated: 2026/07/04 04:06:44 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_game(t_game *game)
{
    ft_putstr_fd("Closing the game. Goodbye!\n", 1);

    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

void move_player(t_game *game, int new_y, int new_x)
{
    if (game->map[new_y][new_x] == '1')
        return ;
    
    game->map[game->player_y][game->player_x] = '0';

    game->map[new_y][new_x] = 'P';

    game->player_y = new_y;
    game->player_x = new_x;

    render_map(game);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        close_game(game);
    else if (keycode == KEY_W)
        move_player(game, game->player_y - 1, game->player_x);
    else if (keycode == KEY_A)
        move_player(game, game->player_y, game->player_x - 1);
    else if (keycode == KEY_S)
        move_player(game, game->player_y + 1, game->player_x);
    else if (keycode == KEY_D)
        move_player(game, game->player_y, game->player_x + 1);
    return (0);
}
