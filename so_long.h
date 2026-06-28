/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:54:45 by esttina           #+#    #+#             */
/*   Updated: 2026/06/28 06:02:10 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"

#include <fcntl.h>
#include <stddef.h>
#include <mlx.h>

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
} t_game;

char **read_map_file(char *file_path);
int check_rectangular(char **map);
int check_walls(char **map);
int check_elements(char **map);
void free_map(char **map);
int check_path(char **map);
void    init_images(t_game *game);
int map_strlen(char *str);


#endif