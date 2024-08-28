/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:48:54 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/22 18:46:14 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_size(t_mlx *game, char *path)
{
	int		row_count;
	int		line;
	char	*tmp;

	row_count = 0;
	game->fd = open(path, O_RDONLY);
	if (game->fd < 0)
		error_fd();
	tmp = get_next_line(game->fd);
	check_map_line(tmp);
	line = ft_strlen(tmp);
	if (tmp[line - 1] == '\n')
		game->g_map->col = (line - 1);
	else
		game->g_map->col = line;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(game->fd);
		row_count++;
	}
	close(game->fd);
	return (row_count);
}

static void	map_malloc(t_mlx *game, char *path)
{
	game->g_map->rows = get_map_size(game, path);
	game->temp_map = (char **)malloc(sizeof(char *) * (game->g_map->rows
				+ 1));
	game->g_map->map = (char **)malloc(sizeof(char *) * (game->g_map->rows
				+ 1));
	if (!game->temp_map || !game->g_map->map)
	{
		if (game->temp_map)
			malloc_free(game, game->temp_map);
		if (game->g_map->map)
			malloc_free(game, game->g_map->map);
		error_message("Memory allocation failed");
		exit(1);
	}
}

static void	load_map(t_mlx *game, char *path)
{
	int		i;
	char	*map_line;
	int		line;

	i = 0;
	map_line = NULL;
	line = game->g_map->rows;
	game->fd = open(path, O_RDWR);
	if (game->fd < 0)
		error_fd();
	while (i < line)
	{
		map_line = get_next_line(game->fd);
		game->g_map->map[i] = ft_strtrim(map_line, "\n");
		free(map_line);
		i++;
	}
	game->g_map->map[line] = NULL;
	close(game->fd);
}

static void	copy_map(t_mlx *game, char *path)
{
	int		line;
	int		i;
	char	*map_line;

	map_line = NULL;
	i = 0;
	game->fd = open(path, O_RDWR);
	if (game->fd < 0)
		error_fd();
	line = game->g_map->rows;
	while (i < line)
	{
		map_line = get_next_line(game->fd);
		game->temp_map[i] = ft_strtrim(map_line, "\n");
		free(map_line);
		i++;
	}
	game->temp_map[line] = NULL;
	close(game->fd);
}

void	read_map(t_mlx *game, char *path)
{
	map_malloc(game, path);
	load_map(game, path);
	copy_map(game, path);
}
