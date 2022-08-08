/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:26:48 by julrodri          #+#    #+#             */
/*   Updated: 2022/04/01 18:05:03 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_len(unsigned int n, int base)
{
	int	len;

	len = 1;
	while (n / base > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_len_long(unsigned long n)
{
	int	len;

	len = 1;
	while (n / 16 > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	format_coverter(const char format, va_list arguments)
{
	int	c;

	if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'c')
	{
		c = va_arg(arguments, int);
		return (write(1, &c, 1));
	}
	else if (format == 's')
		return (print_s(va_arg(arguments, char *)));
	else if (format == 'd' || format == 'i')
		return (print_d_i(va_arg(arguments, int)));
	else if (format == 'u')
		return (print_u(va_arg(arguments, unsigned int)));
	else if (format == 'x')
		return (print_x(va_arg(arguments, unsigned int), 'l'));
	else if (format == 'X')
		return (print_x(va_arg(arguments, unsigned int), 'u'));
	else if (format == 'p')
		return (print_p(va_arg(arguments, unsigned long)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	arguments;

	len = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len = len + format_coverter(*format, arguments);
			format++;
		}
		else
		{
			len += write(1, format, 1);
			format++;
		}	
	}
	va_end(arguments);
	return (len);
}
