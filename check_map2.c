/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:14 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/22 18:46:14 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_map_valid(t_mlx *game, int x, int y)
{
	game->player_count++;
	game->g_map->p_x = x;
	game->g_map->p_y = y;
}

void	e_map_valid(t_mlx *game, int x, int y)
{
	game->g_map->e_x = x;
	game->g_map->e_y = y;
}

void	map_corner_close_y(t_mlx *game, int y)
{
	if (game->g_map->map[y][0] != '1'
		|| game->g_map->map[y][game->g_map->col - 1] != '1')
	{
		error_message("non-valid y map corner");
		free_g_map(game);
	}
}

void	map_corner_close_x(t_mlx *game, int x)
{
	if (game->g_map->map[0][x] != '1'
		|| game->g_map->map[game->g_map->rows - 1][x] != '1')
	{
		error_message("non-valid x map corner");
		free_g_map(game);
	}
}

void	character_valid(t_mlx *game, int x, int y)
{
	if ((game->g_map->map[y][x] != 'P') && (game->g_map->map[y][x] != 'E')
		&& (game->g_map->map[y][x] != 'C')
		&& (game->g_map->map[y][x] != '1')
		&& (game->g_map->map[y][x] != '0'))
	{
		error_message("non-valid character");
		free_g_map(game);
	}
}
