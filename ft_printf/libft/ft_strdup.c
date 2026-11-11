/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:28:42 by mabuhila          #+#    #+#             */
/*   Updated: 2026/09/24 15:47:46 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s);
	ptr = malloc(str_len + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s, str_len);
	ptr[str_len] = '\0';
	return (ptr);
}
