/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:48:42 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 12:39:29 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *s)
{
	ft_printf("Error\n%s", s);
}

void	error_fd(void)
{
	error_message("Map not found");
	exit(1);
}

void	check_map_line(char *tmp)
{
	if (!tmp || !tmp[0])
	{
		error_message("map is empty");
		exit(1);
	}
}

void	free_image(t_mlx *game)
{
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_window(game->mlx, game->window);
}
