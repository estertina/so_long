/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:03:29 by esttina           #+#    #+#             */
/*   Updated: 2026/07/12 00:01:04 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	ft_putstr_fd("Closing the game. Goodbye!\n", 1);
	if (game->map != NULL)
		free_map(game->map);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

static int	check_next_tile(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles_gathered == game->collectibles_total)
		{
			ft_putstr_fd("YOU_WIN!\n", 1);
			close_game(game);
		}
		else
		{
			ft_putstr_fd("You need more wood!\n", 1);
			return (0);
		}
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles_gathered++;
		ft_putstr_fd("Wood: ", 1);
		ft_putnbr_fd(game->collectibles_gathered, 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
}

void	move_player(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (check_next_tile(game, new_y, new_x) == 0)
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	render_map(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, game->player_y - 1, game->player_x);
	else if (keycode == KEY_A)
		move_player(game, game->player_y, game->player_x - 1);
	else if (keycode == KEY_S)
		move_player(game, game->player_y + 1, game->player_x);
	else if (keycode == KEY_D)
		move_player(game, game->player_y, game->player_x + 1);
	return (0);
}
