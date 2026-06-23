/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 03:54:45 by esttina           #+#    #+#             */
/*   Updated: 2026/06/23 01:10:08 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"

//open function
#include <fcntl.h>

//NULL
#include <stddef.h>

//for testing
#include <stdio.h>

char **read_map_file(char *file_path);
int check_rectangular(char **map);
int check_walls(char **map);
int check_elements(char **map);
void free_map(char **map);
int check_path(char **map);


#endif