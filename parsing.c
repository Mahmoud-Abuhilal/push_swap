/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-18 13:29:26 by mabuhila          #+#    #+#             */
/*   Updated: 2026-11-18 13:29:26 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicat(t_list *stack, int num)
{
	while (stack)
	{
		if (get_val(stack) == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	append_node(t_list **stack, int num)
{
	t_list	*node;

	node = ft_lstnew((void *)(intptr_t)num);
	if (!node)
		return (0);
	ft_lstadd_back(stack, node);
	return (1);
}

static int	parse_and_append(t_list **stack, char *input)
{
	char	**split;
	long	num;
	int		i;

	i = 0;
	split = ft_split(input, ' ');
	if (!split || !split[i])
		return (handle_parse_error(split, stack));
	while (split[i])
	{
		if (!is_valid_number(split[i]))
			return (handle_parse_error(split, stack));
		num = ft_atol(split[i]);
		if (num > 2147483647 || num < -2147483648L)
			return (handle_parse_error(split, stack));
		if (has_duplicat(*stack, (int)num) || !append_node(stack, (int)num))
			return (handle_parse_error(split, stack));
		i++;
	}
	free_split(split);
	return (1);
}

static int	parse_flags(t_stacks *stacks, int argc, char **argv, int *i)
{
	int	flag;

	while (*i < argc)
	{
		if (ft_strncmp(argv[*i], "--bench", 8) == 0)
		{
			if (stacks->bench)
				return (0);
			stacks->bench = 1;
		}
		else
		{
			flag = check_algo(argv[*i]);
			if (!flag)
				break ;
			if (stacks->algo_flag)
				return (0);
			stacks->algo_flag = flag;
		}
		(*i)++;
	}
	return (1);
}

int	parse_args(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	if (!parse_flags(stacks, argc, argv, &i))
		return (handle_parse_error(NULL, &stacks->a));
	while (i < argc)
	{
		if (!parse_and_append(&stacks->a, argv[i++]))
			return (0);
	}
	return (1);
}
