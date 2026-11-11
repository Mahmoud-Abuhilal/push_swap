/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:16:43 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/19 15:41:50 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_puthex_len(unsigned int num, char specifier);
int	ft_putchar_len(char c);
int	ft_putstr_len(char *str);
int	ft_putptr_len(void *ptr);
int	ft_putnbr_len(int n);
int	ft_putunsigned_len(unsigned int num);

#endif
