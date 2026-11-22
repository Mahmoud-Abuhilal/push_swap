/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabushai <rabushai@student.42amman.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:14:43 by rabushai          #+#    #+#             */
/*   Updated: 2026/11/22 22:15:02 by rabushai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *s)
{
	rotate(&s->a);
	write(1, "ra\n", 3);
	s->ops[OP_RA]++;
}

void	rb(t_stacks *s)
{
	rotate(&s->b);
	write(1, "rb\n", 3);
	s->ops[OP_RB]++;
}

void	rr(t_stacks *s)
{
	rotate(&s->a);
	rotate(&s->b);
	write(1, "rr\n", 3);
	s->ops[OP_RR]++;
}
