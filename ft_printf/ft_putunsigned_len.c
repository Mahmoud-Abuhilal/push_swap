/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:23:13 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/19 15:34:44 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_len(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_putunsigned_len(num / 10);
	count += ft_putchar_len((num % 10) + '0');
	return (count);
}
