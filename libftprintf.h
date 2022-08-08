/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:31:24 by julrodri          #+#    #+#             */
/*   Updated: 2022/04/01 18:18:50 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			format_coverter(const char format, va_list arguments);
int			ft_printf(const char *format, ...);
int			print_s(char *str);
int			print_d_i(int n);
int			print_u(unsigned int n);
int			print_x(unsigned int n, char upper_or_lower);
int			print_p(unsigned long n);
int			ft_len(unsigned int n, int base);
int			ft_len_long(unsigned long n);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_itoa(int n);

#endif