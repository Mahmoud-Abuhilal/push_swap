/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:06:27 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/19 15:34:40 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar_len('-');
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr_len(nb / 10);
	count += ft_putchar_len((nb % 10) + '0');
	return (count);
}
