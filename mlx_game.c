/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:27 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 15:53:20 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_press(int keycode, t_mlx *game)
{
	if (keycode == 53)
		close_window(game);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 2)
		move_right(game);
	set_image(game);
	return (0);
}

static void	get_image(t_mlx *game)
{
	int	y;
	int	x;

	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &x, &y);
	game->empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &x,
			&y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &x,
			&y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &x, &y);
	game->none_exit = mlx_xpm_file_to_image(game->mlx, "textures/none_exit.xpm",
			&x, &y);
	if (game->wall == NULL || game->coin == NULL || game->empty == NULL
		|| game->exit == NULL || game->player == NULL
		|| game->none_exit == NULL)
	{
		error_message("Missing image file");
		exit(1);
	}
}

void	mlx_game(t_mlx *game)
{
	game->mlx = mlx_init();
	get_image(game);
	game->window = mlx_new_window(game->mlx, game->g_map->col * 64,
			game->g_map->rows * 64, "so_long");
	set_image(game);
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
