/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaraden <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:01:18 by bkaraden          #+#    #+#             */
/*   Updated: 2022/02/16 14:44:10 by bkaraden         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(long double number, int base, int is_upper)
{
	int	count;

	count = 1;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
		count++;
	}
	if (number >= base)
		count += ft_putnbr(((unsigned long)number / base), base, is_upper);
	if (is_upper)
		write(1, &"0123456789ABCDEF"[(unsigned long)number % base], 1);
	else
		write(1, &"0123456789abcdef"[(unsigned long)number % base], 1);
	return (count);
}

int	ft_pointer(unsigned long address, int base, int is_upper)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr(address, base, is_upper);
	return (count);
}
