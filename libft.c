/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:57 by julrodri          #+#    #+#             */
/*   Updated: 2022/04/01 15:50:06 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*r;
	int		i;

	r = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!r)
		return (0);
	i = 0;
	while (i <= ft_strlen(s))
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}

static int	ft_count_alg(int n)
{
	int	alg;

	alg = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		alg++;
	}
	return (alg);
}

static char	ft_algtochr(int n)
{
	if (n < 10)
		return (n + 48);
	else
		return (ft_algtochr(n % 10));
}

char	*ft_itoa(int n)
{
	char	*r;
	int		alg;
	int		n_temp;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = n < 0;
	n_temp = n * (1 - negative * 2);
	alg = ft_count_alg(n_temp);
	r = (char *) malloc((negative + alg + 1) * sizeof(char));
	if (!r)
		return (0);
	if (negative)
		r[0] = '-';
	r[negative + alg] = '\0';
	while (alg > 0)
	{
		r[alg + negative - 1] = ft_algtochr(n_temp);
		n_temp = n_temp / 10;
		alg--;
	}
	return (r);
}
