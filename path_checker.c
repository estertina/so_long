/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 20:56:55 by esttina           #+#    #+#             */
/*   Updated: 2026/06/22 21:50:40 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **duplicate_map(char **map, int rows)
{
    char **copy;
    int i;

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

int check_path(char **map)
{
    char    **duplicate;
    int     x;
    int     y;
    int     p_x;
    int     p_y;

    y = 0;
    // counting rows
    while (map[y])
        y++;

    duplicate = duplicate_map(map, y);
    if (!duplicate)
        return (0);
    
    y = 0;
    while(duplicate[y] != NULL)
    {
        x = 0;
        while(duplicate[y][x] != '\0')
        {
            if (duplicate[y][x] == 'P')
            {
                p_x = x;
                p_y = y;
            }
            x++;
        }
        y++;
    }

    free_map(duplicate);
    return (1);
}   