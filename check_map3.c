/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:07 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 11:42:03 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_count_check(t_mlx *game)
{
	if ((game->count_collectable < 1) || (game->exit_count != 1)
		|| (game->player_count != 1))
	{
		error_message("Failure character count");
		free_g_map(game);
	}
}

static void	path_recursive(char **map, int x, int y)
{
	map[y][x] = '*';
	if (map[y + 1][x] != '1' && map[y + 1][x] != '*')
		path_recursive(map, x, y + 1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != '*')
		path_recursive(map, x, y - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '*')
		path_recursive(map, x + 1, y);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '*')
		path_recursive(map, x - 1, y);
}

void	is_game_played(t_mlx *game)
{
	int	x;
	int	y;

	path_recursive(game->temp_map, game->g_map->p_x, game->g_map->p_y);
	y = -1;
	while (++y < game->g_map->rows)
	{
		x = -1;
		while (++x < game->g_map->col)
		{
			if (game->temp_map[y][x] != '*' && game->temp_map[y][x] != '1'
				&& game->temp_map[y][x] != '0')
			{
				error_message("unplayable map");
				free_g_map(game);
				exit(1);
			}
		}
	}
}
