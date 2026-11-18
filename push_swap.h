/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabuhila <mabuhila@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 11:30:46 by mabuhila         #+#    #+#              */
/*   Updated: 2026/11/11 11:33:10 by mabuhila        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		algo_flag;
	int		bench;
	double	disorder;
	int		ops[11];
}	t_stacks;

int		check_algo(char *type);
int		is_valid_number(char *str);
void	free_split(char **str);
int		handle_parse_error(char **str, t_list **stack);
int		parse_and_append(t_list **stack, char *input);
int		parse_args(t_stacks *stacks, int argc, char **argv);
int		is_sorted(t_list *stack);

#endif