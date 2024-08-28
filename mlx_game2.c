/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:35 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 16:17:43 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	yx_update(t_mlx *game)
{
	if (game->g_map->map[game->g_map->p_y][game->g_map->p_x] != 'E')
		game->g_map->map[game->g_map->p_y][game->g_map->p_x] = '0';
	game->p_step++;
	ft_printf("move steps: %d\n", game->p_step);
}

void	finish_game(t_mlx *game)
{
	ft_printf("move steps: %d\n", ++game->p_step);
	ft_printf("<<congratulations you finished the game>>\n");
	close_window(game);
}

void	none_exit_chage(t_mlx *game)
{
	game->g_map->map[game->g_map->e_y][game->g_map->e_x] = 'E';
	set_image(game);
}

void	move_up(t_mlx *game)
{
	if (game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] == '1')
		return ;
	else if (game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] == '0')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] = 'P';
		game->g_map->p_y--;
	}
	else if (game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] == 'C')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] = 'P';
		game->g_map->p_y--;
		game->collected++;
	}
	else if (game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->g_map->map[game->g_map->p_y - 1][game->g_map->p_x] = 'P';
		game->g_map->p_y--;
		none_exit_chage(game);
	}
}

void	move_down(t_mlx *game)
{
	if (game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] == '1')
		return ;
	else if (game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] == '0')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] = 'P';
		game->g_map->p_y++;
	}
	else if (game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] == 'C')
	{
		yx_update(game);
		game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] = 'P';
		game->g_map->p_y++;
		game->collected++;
	}
	else if (game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->g_map->map[game->g_map->p_y + 1][game->g_map->p_x] = 'P';
		game->g_map->p_y++;
		none_exit_chage(game);
	}
}
