/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:58:10 by zayaz             #+#    #+#             */
/*   Updated: 2024/07/26 16:49:00 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_control(va_list arg, char c)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		total += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
	{
		total += ft_putstr("0x");
		total += ft_put_ptrhex(va_arg(arg, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		total += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		total += ft_put_unbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		total += ft_puthex(va_arg(arg, unsigned int), c);
	else if (c == 'X')
		total += ft_puthex(va_arg(arg, unsigned int), c);
	else if (c == '%')
		total += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (total);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	len = 0;
	va_start(arg, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_control(arg, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
