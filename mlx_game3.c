/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:46 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 16:52:58 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_mlx *game)
{
	if (game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] == '1')
		return ;
	else if (game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] == '0')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] = 'P';
		game->g_map->p_x--;
	}
	else if (game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] == 'C')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] = 'P';
		game->g_map->p_x--;
		game->collected++;
	}
	else if (game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->g_map->map[game->g_map->p_y][game->g_map->p_x - 1] = 'P';
		game->g_map->p_x--;
		none_exit_chage(game);
	}
}

void	move_right(t_mlx *game)
{
	if (game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] == '1')
		return ;
	else if (game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] == '0')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] = 'P';
		game->g_map->p_x++;
	}
	else if (game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] == 'C')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] = 'P';
		game->g_map->p_x++;
		game->collected++;
	}
	else if (game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->g_map->map[game->g_map->p_y][game->g_map->p_x + 1] = 'P';
		game->g_map->p_x++;
		none_exit_chage(game);
	}
}

static void	put_check_image(t_mlx *game, int x, int y)
{
	if (game->g_map->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x * 64, y
			* 64);
	else if (game->g_map->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->empty, x * 64, y
			* 64);
	else if (game->g_map->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->coin, x * 64, y
			* 64);
	else if (game->g_map->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, x * 64, y
			* 64);
	else if (game->g_map->map[y][x] == 'E')
	{
		if (game->g_map->map[game->g_map->p_y][game->g_map->p_x]
				== game->g_map->map[game->g_map->e_y][game->g_map->e_x])
			mlx_put_image_to_window(game->mlx, game->window, game->none_exit, x
				* 64, y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->exit, x * 64,
				y * 64);
	}
}

void	set_image(t_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->g_map->rows)
	{
		x = 0;
		while (game->g_map->map[y][x])
		{
			put_check_image(game, x, y);
			x++;
		}
		y++;
	}
}
