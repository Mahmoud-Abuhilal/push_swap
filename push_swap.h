/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mabuhila <mabuhila@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 11:30:46 by mabuhila         #+#    #+#              */
/*   Updated: 2026/11/23 13:12:09 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

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
}			t_op;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		algo_flag;
	int		bench;
	double	disorder;
	int		ops[11];
}			t_stacks;

int			check_algo(char *type);
int			is_valid_number(char *str);
void		free_split(char **str);
int			handle_parse_error(char **str, t_list **stack);
int			parse_and_append(t_list **stack, char *input);
int			parse_args(t_stacks *stacks, int argc, char **argv);
int			is_sorted(t_list *stack);
double		compute_disorder(t_list *stack);
int			get_val(t_list *node);
int			is_sorted(t_list *stack);
void		sort_stack(t_stacks *stacks);
void		del_content(void *content);
int			free_stacks(t_stacks *stacks, int exit_code);
void		print_bench(t_stacks *stack);
const char	*get_op_name(int op);
void		swap(t_list **stack);
void		push(t_list **src, t_list **dest);
void		rotate(t_list **stack);
void		reverse_rotate(t_list **stack);
void		sa(t_stacks *s);
void		sb(t_stacks *s);
void		ss(t_stacks *s);
void		pa(t_stacks *s);
void		pb(t_stacks *s);
void		ra(t_stacks *s);
void		rb(t_stacks *s);
void		rr(t_stacks *s);
void		rra(t_stacks *s);
void		rrb(t_stacks *s);
void		rrr(t_stacks *s);

#endif
