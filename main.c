/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:42:24 by esttina           #+#    #+#             */
/*   Updated: 2026/05/28 18:42:31 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
    int fd;

    // two arguments: program name & map file
    if (ac != 2)
    {
        ft_putstr_fd("Error\nPlease provide a map file.\n", 1);
        return (1);
    }

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error\nCannot open file.\n" ,1);
        return (1);
    }

    ft_putstr_fd("Success! We opened the file.\n", 1);

    close(fd);
    return (0);
}