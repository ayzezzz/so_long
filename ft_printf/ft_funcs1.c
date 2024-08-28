/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:15:06 by zayaz             #+#    #+#             */
/*   Updated: 2023/12/25 12:29:36 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_ptrhex(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_put_ptrhex(ptr / 16);
	if ((ptr % 16) < 10)
		len += ft_putchar((ptr % 16) + '0');
	else
		len += ft_putchar((ptr % 16) - 10 + 'a');
	return (len);
}
