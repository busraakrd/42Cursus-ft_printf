/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaraden <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:00:22 by bkaraden          #+#    #+#             */
/*   Updated: 2022/02/22 13:24:50 by bkaraden         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(char str, va_list arguments)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(arguments, int));
	else if (str == 's')
		count += ft_putstr(va_arg(arguments, char *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(arguments, int), 10, 0);
	else if (str == 'u')
		count += ft_putnbr(va_arg(arguments, unsigned int), 10, 0);
	else if (str == 'p')
		count += ft_pointer(va_arg(arguments, unsigned long), 16, 0);
	else if (str == 'x')
		count += ft_putnbr(va_arg(arguments, unsigned int), 16, 0);
	else if (str == 'X')
		count += ft_putnbr(va_arg(arguments, unsigned int), 16, 1);
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		count;

	count = 0;
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_formats(*(str + 1), arguments);
			str++;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(arguments);
	return (count);
}

/*int main()
{
	char *str;
 	int		my;
 	int 	orj;
	str = 0;
 	my = ft_printf("%s", str);
 	orj = printf("%s", str);
    printf("%d", my);
    printf("%d", orj);
    return(0);
 }*/
