/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabushai <rabushai@student.42amman.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:16:14 by rabushai          #+#    #+#             */
/*   Updated: 2026/11/22 22:16:28 by rabushai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *s)
{
	reverse_rotate(&s->a);
	write(1, "rra\n", 4);
	s->ops[OP_RRA]++;
}

void	rrb(t_stacks *s)
{
	reverse_rotate(&s->b);
	write(1, "rrb\n", 4);
	s->ops[OP_RRB]++;
}

void	rrr(t_stacks *s)
{
	reverse_rotate(&s->a);
	reverse_rotate(&s->b);
	write(1, "rrr\n", 4);
	s->ops[OP_RRR]++;
}
