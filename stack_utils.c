/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:06:52 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/19 21:06:52 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_val(t_list *node)
{
	return ((int)(intptr_t)node->content);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (get_val(stack) > get_val(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_stack(t_stacks *stacks)
{
	if (stacks->algo_flag == 1)
		sort_simple(stacks);
	else if (stacks->algo_flag == 2)
		sort_medium(stacks);
	else if (stacks->algo_flag == 3)
		sort_complex(stacks);
	else
		sort_adaptive(stacks);
}

void	del_content(void *content)
{
	(void)content;
}

int	free_stacks(t_stacks *stacks, int exit_code)
{
	ft_lstclear(&stacks->a, del_content);
	ft_lstclear(&stacks->b, del_content);
	return (exit_code);
}
