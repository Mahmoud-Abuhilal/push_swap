/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabushai <rabushai@student.42amman.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:26:46 by rabushai          #+#    #+#             */
/*   Updated: 2026/11/22 22:23:15 by rabushai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!src || !(*src) || !dest)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}
