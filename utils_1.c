/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:49:04 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 11:28:11 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_free(t_mlx *game, char **map)
{
	free(map);
	free(game->g_map);
	free(game);
}

static void	free_map(t_mlx *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->g_map->rows)
		free(map[i++]);
	if (map)
		free(map);
}

static void	close_map(t_mlx *game)
{
	free_map(game, game->temp_map);
	free_map(game, game->g_map->map);
	free(game->g_map);
}

void	free_g_map(t_mlx *game)
{
	close_map(game);
	free(game);
	exit(1);
}

int	close_window(t_mlx *game)
{
	free_image(game);
	close_map(game);
	free(game);
	ft_printf("close window");
	exit(0);
}
