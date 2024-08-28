/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:29:06 by zayaz             #+#    #+#             */
/*   Updated: 2023/12/25 12:29:46 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int number)
{
	int	len;

	len = 0;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (number < 0)
	{
		len += ft_putchar('-');
		number *= -1;
		len += ft_putnbr(number);
	}
	else if (number >= 0 && number <= 9)
		len += ft_putchar(number + 48);
	else
	{
		len += ft_putnbr(number / 10);
		len += ft_putnbr(number % 10);
	}
	return (len);
}

int	ft_put_unbr(unsigned int number)
{
	int	len;

	len = 0;
	if (number >= 0 && number <= 9)
		len += ft_putchar(number + 48);
	else
	{
		len += ft_put_unbr(number / 10);
		len += ft_put_unbr(number % 10);
	}
	return (len);
}

int	ft_puthex(unsigned int i, char type)
{
	int	len;

	len = 0;
	if (i >= 16)
		len += ft_puthex(i / 16, type);
	if ((i % 16) < 10)
		len += ft_putchar((i % 16) + 48);
	else
	{
		if (type == 'x')
			len += ft_putchar((i % 16) - 10 + 'a');
		else
			len += ft_putchar((i % 16) - 10 + 'A');
	}
	return (len);
}
