/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:45:11 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/22 14:53:03 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_args(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr_len(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned_len(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex_len(va_arg(args, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_puthex_len(va_arg(args, unsigned int), 'X'));
	else if (format == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += print_args(*format, args);
		}
		else
			count += ft_putchar_len(*format);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}
