/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:42:24 by esttina           #+#    #+#             */
/*   Updated: 2026/06/21 23:18:34 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
    char **map;

    // two arguments: program name & map file
    if (ac != 2)
    {
        ft_putstr_fd("Error\nPlease provide a map file.\n", 1);
        return (1);
    }

    map = read_map_file(av[1]);
    if (!map)
    {
        ft_putstr_fd("Error\nCannot open file.\n" ,1);
        return (1);
    }

    if (check_rectangular(map) == 0)
    {
        ft_putstr_fd("Error\nThe map is not a valid rectangle.\n", 1);
        free_map(map);
        return (1);
    }

    if (check_walls(map) == 0)
    {
        ft_putstr_fd("Error\nThe map is not surrounded by walls.\n", 1);
        free_map(map);
        return (1);
    }

    if (check_elements(map) == 0)
    {
        ft_putstr_fd("Error\nInvalid map elements.\n", 1);
        free_map(map);
        return (1);
    }
    
    ft_putstr_fd("Success! We opened and validated the file.\n", 1);

    free_map(map);
    return (0);
}
