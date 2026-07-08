/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:54:25 by esttina           #+#    #+#             */
/*   Updated: 2026/07/04 05:28:03 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_rows(char *file_path)
{
    int fd;
    int count;
    char *line;

    count = 0;
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

char **read_map_file(char *file_path)
{
    int fd;
    int rows;
    int i;
    char **map;

    //How tall is the map
    rows = count_rows(file_path);
    if (rows <= 0)
        return (NULL);
    
    //Allocate memory for pointers (rows + 1 for NULL termination)
    map = malloc(sizeof(char *) * (rows + 1));
    if (!map)
        return (NULL);
    
    //
    fd = open(file_path, O_RDONLY);

    if (fd < 0)
    {
        free(map);
        return (NULL);
    }
    
    i = 0;
    while (i < rows)
    {
        map[i] = get_next_line(fd);
        i++;
    }

    map[i] = NULL;

    close(fd);
    return (map);
}

void free_map(char **map)
{
    int i;

    if (!map)
        return ;

    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void player_position(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->map[y] != NULL)
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
            if (game->map[y][x] == 'P')
            {
                game->player_y = y;
                game->player_x = x;
            }
            else if (game->map[y][x] == 'C')
                game->collectibles_total++;
            x++;
        }
        y++;
    }
}