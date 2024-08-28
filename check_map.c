/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:45:02 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 11:41:07 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_size_check(t_mlx *game)
{
	if (game->g_map->rows > 22 || game->g_map->col > 55)
	{
		error_message("Map size is too big");
		free_g_map(game);
	}
}

static void	line_valid(t_mlx *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->g_map->rows)
	{
		len = ft_strlen(game->g_map->map[i]);
		if (len != game->g_map->col)
		{
			error_message("line size");
			free_g_map(game);
		}
		i++;
	}
}

static void	map_valid(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->g_map->rows)
	{
		x = 0;
		while (x < game->g_map->col)
		{
			character_valid(game, x, y);
			map_corner_close_x(game, x);
			if (game->g_map->map[y][x] == 'E')
			{
				game->exit_count++;
				e_map_valid(game, x, y);
			}
			else if (game->g_map->map[y][x] == 'P')
				p_map_valid(game, x, y);
			else if (game->g_map->map[y][x] == 'C')
				game->count_collectable++;
			x++;
		}
		map_corner_close_y(game, y);
		y++;
	}
}

void	check_map(t_mlx *game)
{
	map_size_check(game);
	line_valid(game);
	map_valid(game);
	character_count_check(game);
	is_game_played(game);
}
