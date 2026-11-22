/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabushai <rabushai@student.42amman.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:03:30 by rabushai          #+#    #+#             */
/*   Updated: 2026/11/22 22:21:08 by rabushai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *s)
{
	swap(&s->a);
	write(1, "sa\n", 3);
	s->ops[OP_SA]++;
}

void	sb(t_stacks *s)
{
	swap(&s->b);
	write(1, "sb\n", 3);
	s->ops[OP_SB]++;
}

void	ss(t_stacks *s)
{
	swap(&s->a);
	swap(&s->b);
	write(1, "ss\n", 3);
	s->ops[OP_SS]++;
}

void	pa(t_stacks *s)
{
	push(&s->b, &s->a);
	write(1, "pa\n", 3);
	s->ops[OP_PA]++;
}

void	pb(t_stacks *s)
{
	push(&s->a, &s->b);
	write(1, "pb\n", 3);
	s->ops[OP_PB]++;
}
