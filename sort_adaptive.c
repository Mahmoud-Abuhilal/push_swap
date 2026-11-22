/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:15:16 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/19 21:15:16 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stacks *stacks)
{
	if (stacks->disorder < 0.2)
		sort_simple(stacks);
	else if (stacks->disorder < 0.5)
		sort_medium(stacks);
	else
		sort_complex(stacks);
}
