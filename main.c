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

int	check_algo(char *type)
{
	if (ft_strncmp(type, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(type, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(type, "--complex", 10) == 0)
		return (3);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	handle_parse_error(char **str, t_list **stack)
{
	if (str)
		free_split(str);
	ft_lstclear(stack, NULL);
	write(2, "Error\n", 6);
	return (0);
}

static int	has_duplicat(t_list *stack, int num)
{
	while (stack)
	{
		if ((int)(intptr_t) stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	append_node(t_list **stack, int num)
{
	t_list	*node;

	node = ft_lstnew((void *)(intptr_t) num);
	if (!node)
		return (0);
	ft_lstadd_back(stack, node);
	return (1);
}

int	parse_and_append(t_list **stack, char *input)
{
	char	**split;
	long	num;
	int		i;
	int		is_valid;

	i = 0;
	is_valid = 0;
	split = ft_split(input, ' ');
	if (!split || !split[i])
		return (handle_parse_error(split, stack));
	while (split[i])
	{
		is_valid = is_valid_number(split[i]);
		if (!is_valid)
			return (handle_parse_error(split, stack));
		num = ft_atol(split[i]);
		if (num > 2147483647 || num < -2147483648L)
			return (handle_parse_error(split, stack));
		if (has_duplicat(*stack, (int) num) || !append_node(stack, (int) num))
			return (handle_parse_error(split, stack));
		i++;
	}
	free_split(split);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		algo_flag;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	algo_flag = check_algo(argv[i]);
	if (algo_flag)
		i++;
	while (i <= argc)
		if (!parse_and_append(&stack_a, argv[i++]))
		return (1);
}
