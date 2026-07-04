/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:54:45 by esttina           #+#    #+#             */
/*   Updated: 2026/07/04 05:09:27 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"

#include <fcntl.h>
#include <stddef.h>
#include <mlx.h>
// #include <stdio.h>

#define TILE_SIZE 32

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int map_w;
    int map_h;
    void *img_wall;
    void *img_floor;
    void *img_player;
    void *img_collectible;
    void *img_exit;
    int player_x;
    int player_y;
} t_game;

#ifdef __linux__
#   define KEY_ESC 65307
#   define KEY_W 119
#   define KEY_A 97
#   define KEY_S 115
#   define KEY_D 100

#elif defined (__APPLE__)
#   define KEY_ESC 53
#   define KEY_W 13
#   define KEY_A 0
#   define KEY_S 1
#   define KEY_D 2
#endif

char    **read_map_file(char *file_path);
int     check_rectangular(char **map);
int     check_walls(char **map);
int     check_elements(char **map);
void    free_map(char **map);
int     check_path(char **map);
void    init_images(t_game *game);
int     map_strlen(char *str);
int     render_map(t_game *game);
int     close_game(t_game *game);
int     key_hook(int keycode, t_game *game);
void    player_position(t_game *game);
void    move_player(t_game *game, int new_y, int new_x);


#endif