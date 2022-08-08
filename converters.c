/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:46:11 by julrodri          #+#    #+#             */
/*   Updated: 2022/04/04 09:53:51 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_s(char *str)
{
	if (!str)
		return (write (1, "(null)", 6 * sizeof (char)));
	return (write (1, str, ft_strlen(str) * sizeof (char)));
}

int	print_d_i(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	print_u(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_len(n, 10);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

int	print_x(unsigned int n, char upper_or_lower)
{
	char	*hexa;
	char	*str;
	int		len;

	len = ft_len(n, 16);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	if (upper_or_lower == 'l')
		hexa = ft_strdup("0123456789abcdef");
	else
		hexa = ft_strdup("0123456789ABCDEF");
	while (len > 0)
	{
		str[len - 1] = hexa[n % 16];
		n = n / 16;
		len--;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	free(hexa);
	return (len);
}

int	print_p(unsigned long n)
{
	char	*hexa;
	char	*str;
	int		len;

	if (n == 0)
		return (write(1, "(nil)", 5 * sizeof(char)));
	len = ft_len_long(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	hexa = ft_strdup("0123456789abcdef");
	while (len > 0)
	{
		str[len - 1] = hexa[n % 16];
		n = n / 16;
		len--;
	}
	len = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, len);
	free(str);
	free(hexa);
	return (len + 2);
}
