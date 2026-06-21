/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:54:25 by esttina           #+#    #+#             */
/*   Updated: 2026/06/21 16:52:25 by esttina          ###   ########.fr       */
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