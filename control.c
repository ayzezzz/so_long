/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:59:20 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/22 17:54:49 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		error_message("Wrong file path");
		close(fd);
		exit(1);
	}
	close(fd);
}

static void	ber_control(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 5] == '/')
	{
		error_message("Hidden file extension");
		exit(1);
	}
	if (path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3] != 'b'
		|| path[len - 4] != '.')
	{
		error_message("Write file extension");
		exit(1);
	}
}

void	first_control(char *path)
{
	file_control(path);
	ber_control(path);
}
