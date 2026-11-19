/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:21:49 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/19 17:21:49 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char    *format_percent(char *full, char *dec)
{
    char *tmp;
    char *result;

    if (!full || !dec)
    {
        free(full);
        free(dec);
        return (NULL);
    }
    tmp = ft_strjoin(full, ".");
    free(full);
    if (!tmp)
    {
        free(dec);
        return (NULL);
    }
    result = ft_strjoin(tmp, dec);
    free(tmp);
    free(dec);
    if (!result)
        return (NULL);
    tmp = ft_strjoin(result, "%");
    free(result);
    return (tmp);
}

static char    *get_disorder(double disorder)
{
    int    int_part;
    char    *full;
    char    *dec_part;
    char    *tmp;

    int_part = (int)(disorder * 10000 + 0.5);
    full = ft_itoa(int_part / 100);
    dec_part = ft_itoa(int_part % 100);
    if (dec_part && int_part % 100 < 10)
    {
        tmp = ft_strjoin("0", dec_part);
        free(dec_part);
        dec_part = tmp;
    }
    return (format_percent(full, dec_part));
}

static char	*get_strategy(t_stacks *stacks)
{
	if (stacks->algo_flag == 1)
		return ("Simple / O(n^2)");
	if (stacks->algo_flag == 2)
		return ("Medium / O(n√n)");
	if (stacks->algo_flag == 3)
		return ("Complex / O(n log n)");
	if (stacks->disorder < 0.2)
		return ("Adaptive / O(n^2)");
	if (stacks->disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

static void    print_ops(t_stacks *stack, int start, int end)
{
    const char  *op_names[11] = {"sa:  ", "sb:  ", "ss:  ", "pa:  ", "pb:  ",
        "ra:  ", "rb:  ", "rr:  ", "rra:  ", "rrb:  ", "rrr:  "};

    ft_putstr_fd("[bench] ", 2);
    while (start <= end)
    {
        ft_putstr_fd((char *)op_names[start], 2);
        ft_putnbr_fd(stack->ops[start], 2);
        if (start < end)
            ft_putstr_fd("  ", 2);
        start++;
    }
    ft_putstr_fd("\n", 2);
}

void    print_bench(t_stacks *stack)
{
    char *disorder;
    int total_ops;
    int i;

    disorder = get_disorder(stack->disorder);
    if (!disorder)
        return ;
    total_ops = 0;
    i = -1;
    while(++i < 11)
        total_ops += stack->ops[i];
    ft_putstr_fd("[bench] disorder:  ", 2);
    ft_putstr_fd(disorder, 2);
    ft_putstr_fd("\n", 2);
    free(disorder);
    ft_putstr_fd("[bench] strategy:  ", 2);
    ft_putstr_fd(get_strategy(stack), 2);
    ft_putstr_fd("\n", 2);
    ft_putstr_fd("[bench] total_ops:  ", 2);
    ft_putnbr_fd(total_ops, 2);
    ft_putstr_fd("\n", 2);
    print_ops(stack, 0, 4);
    print_ops(stack, 5, 10);
}