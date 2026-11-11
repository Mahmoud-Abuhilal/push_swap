/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:14:15 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/19 15:34:42 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(uintptr_t addr_num)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (addr_num >= 16)
		count += ft_puthex_ptr(addr_num / 16);
	count += ft_putchar_len(hex[addr_num % 16]);
	return (count);
}

int	ft_putptr_len(void *ptr)
{
	uintptr_t	addr;
	int			count;

	if (!ptr)
		return (ft_putstr_len("(nil)"));
	count = 0;
	addr = (uintptr_t) ptr;
	count += ft_putstr_len("0x");
	count += ft_puthex_ptr(addr);
	return (count);
}
