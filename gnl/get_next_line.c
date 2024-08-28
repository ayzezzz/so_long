/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:38:41 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 16:48:15 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readfd(int fd, char *stc)
{
	char	*buffer;
	int		control;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	control = 1;
	while (!ft_nlcntrl(stc) && control != 0)
	{
		control = read(fd, buffer, BUFFER_SIZE);
		if (control == -1)
		{
			free(stc);
			free(buffer);
			return (NULL);
		}
		buffer[control] = '\0';
		stc = ft_strjoin(stc, buffer);
	}
	free(buffer);
	return (stc);
}

static char	*ft_updtstc(char *stc)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (stc[i] && stc[i] != '\n')
		i++;
	if (!stc[i])
	{
		free(stc);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlens(stc) - i + 1));
	if (!s)
		return (NULL);
	i++;
	while (stc[i])
		s[j++] = stc[i++];
	s[j] = '\0';
	free(stc);
	return (s);
}

static char	*ft_nlbefore(char *stc)
{
	char	*str;
	int		i;

	i = 0;
	if (!stc[i])
		return (NULL);
	while (stc[i] && stc[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stc[i] && stc[i] != '\n')
	{
		str[i] = stc[i];
		i++;
	}
	if (stc[i] == '\n')
	{
		str[i] = stc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stc = ft_readfd(fd, stc);
	if (!stc || !*stc)
	{
		if (stc)
			free(stc);
		stc = NULL;
		return (NULL);
	}
	str = ft_nlbefore(stc);
	stc = ft_updtstc(stc);
	return (str);
}
