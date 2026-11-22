/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:33:15 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/22 20:33:15 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*get_op_name(int op)
{
	if (op == 0)
		return ("sa:  ");
	if (op == 1)
		return ("sb:  ");
	if (op == 2)
		return ("ss:  ");
	if (op == 3)
		return ("pa:  ");
	if (op == 4)
		return ("pb:  ");
	if (op == 5)
		return ("ra:  ");
	if (op == 6)
		return ("rb:  ");
	if (op == 7)
		return ("rr:  ");
	if (op == 8)
		return ("rra:  ");
	if (op == 9)
		return ("rrb:  ");
	return ("rrr:  ");
}
