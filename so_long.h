/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:33:47 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 12:30:24 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	int		rows;
	int		col;
	char	**map;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;

}			t_map;

typedef struct s_mlx
{
	int		fd;

	t_map	*g_map;
	char	**temp_map;
	int		exit_count;
	int		player_count;
	int		count_collectable;
	void	*mlx;
	void	*window;
	void	*player;
	void	*wall;
	void	*empty;
	void	*exit;
	void	*none_exit;
	void	*coin;
	int		p_step;
	int		collected;
}			t_mlx;

void		error_message(char *s);
void		first_control(char *path);
void		read_map(t_mlx *game, char *path);
void		check_map_line(char *tmp);
void		error_fd(void);
void		check_map(t_mlx *game);
void		malloc_free(t_mlx *game, char **map);
int			close_window(t_mlx *game);
void		free_g_map(t_mlx *game);
void		free_image(t_mlx *game);
void		e_map_valid(t_mlx *game, int x, int y);
void		p_map_valid(t_mlx *game, int x, int y);
void		character_valid(t_mlx *game, int x, int y);
void		map_corner_close_x(t_mlx *game, int x);
void		map_corner_close_y(t_mlx *game, int y);
void		character_count_check(t_mlx *game);
void		is_game_played(t_mlx *game);
void		move_up(t_mlx *game);
void		yx_update(t_mlx *game);
void		finish_game(t_mlx *game);
void		none_exit_chage(t_mlx *game);
void		set_image(t_mlx *game);
void		move_down(t_mlx *game);
void		move_right(t_mlx *game);
void		move_left(t_mlx *game);
void		mlx_game(t_mlx *game);

#endif