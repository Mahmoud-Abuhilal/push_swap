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
