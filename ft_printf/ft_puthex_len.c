/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:58:19 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/19 16:07:16 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_len(unsigned int num, char specifier)
{
	char	*hex;
	int		count;

	count = 0;
	if (specifier == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_puthex_len(num / 16, specifier);
	count += ft_putchar_len(hex[num % 16]);
	return (count);
}
