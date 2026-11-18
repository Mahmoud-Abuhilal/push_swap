/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-18 13:29:39 by mabuhila          #+#    #+#             */
/*   Updated: 2026-11-18 13:29:39 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	check_algo(char *type)
{
	if (ft_strncmp(type, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(type, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(type, "--complex", 10) == 0)
		return (3);
    if (ft_strncmp(type, "--adaptive", 11) == 0)
        return (4);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	handle_parse_error(char **str, t_list **stack)
{
	if (str)
		free_split(str);
	ft_lstclear(stack, NULL);
	write(2, "Error\n", 6);
	return (0);
}