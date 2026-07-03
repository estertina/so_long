/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:03:29 by esttina           #+#    #+#             */
/*   Updated: 2026/07/04 01:23:02 by esttina          ###   ########.fr       */
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

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        close_game(game);
    else if (keycode == KEY_W)
        ft_putstr_fd("Player moved UP!\n", 1);
    else if (keycode == KEY_A)
        ft_putstr_fd("Player moved LEFT!\n", 1);
    else if (keycode == KEY_S)
        ft_putstr_fd("Player moved DOWN!\n", 1);
    else if (keycode == KEY_D)
        ft_putstr_fd("Player moved RIGHT!\n", 1);
    return (0);
}