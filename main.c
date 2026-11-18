/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:09:38 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/12 19:19:22 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((int)(intptr_t) stack->content
		> (int)(intptr_t) stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void sort_stack(t_stacks *stacks)
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

static int	free_stacks(t_stacks *stacks, int exit_code)
{
	ft_lstclear(&stacks->a, NULL);
	ft_lstclear(&stacks->b, NULL);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	ft_bzero(&stacks, sizeof(t_stacks));
	if (!parse_args(&stacks, argc, argv))
		return (free_stacks(&stacks, 1));
	stacks.disorder = compute_disorder(stacks.a);
	if (stacks.a && !is_sorted(stacks.a))
		sort_stack(&stacks);
	return (free_stacks(&stacks, 0));
}
