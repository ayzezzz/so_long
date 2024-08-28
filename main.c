/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:33:52 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 16:41:35 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_mlx));
		game->g_map = ft_calloc(1, sizeof(t_map));
		if (!game || !game->g_map)
		{
			error_message("failed to allocate space in memsory");
			if (game)
				free(game);
			if (game->g_map)
				free(game->g_map);
			exit(1);
		}
		first_control(argv[1]);
		read_map(game, argv[1]);
		check_map(game);
		mlx_game(game);
	}
	else
		error_message("number of arguments must be two");
}
