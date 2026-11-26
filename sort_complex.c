/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:42:47 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/23 22:42:47 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_stacks *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pb(stack);
		i++;
	}
}

void	sort_complex(t_stacks *stack)
{
	int	n;
	int	block_size;

	n = ft_lstsize(stack->a);
	block_size = 1;
	while (block_size <= n)
	{
		split_stack(stack, block_size);
		block_size *= 2;
	}
}
