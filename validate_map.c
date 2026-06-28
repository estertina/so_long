/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 18:59:19 by esttina           #+#    #+#             */
/*   Updated: 2026/06/28 05:44:34 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);

    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

int check_rectangular(char **map)
{
    int width;
    int i;
    
    if (!map || !map[0])
        return (0);
    
    width = map_strlen(map[0]);
    i = 1;

    while(map[i] != NULL)
    {
        if (map_strlen(map[i]) != width)
            return (0); //Failure
        i++;
    }
    return (1);
}

int check_walls(char **map)
{
    int i;
    int j;
    int width;
    int height;

    j = 0;
    i = 0;
    height = 0;
    width = map_strlen(map[0]);

    while (map[height] != NULL)
        height++;
    
    while(j < width)
    {
        if (map[0][j] != '1' || map[height - 1][j] != '1')
            return (0);
        j++;
    }

    while (i < height)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
            return (0);
        i++;
    }
    
    return (1);
}

int check_elements(char **map)
{
    int i;
    int j;
    int p;
    int e;
    int c;

    p = 0;
    e = 0;
    c = 0;
    i = 0;
    
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0' && map[i][j] != '\n')
        {
            if (map[i][j] == 'P')
                p++;
            else if (map[i][j] == 'E')
                e++;
            else if (map[i][j] == 'C')
                c++;
            else if (map[i][j] != '0' && map[i][j] != '1')
                return (0);
            j++;
        }
        i++;
    }
    if (p == 1 && e == 1 && c >= 1)
        return (1);
    else
        return (0);
}