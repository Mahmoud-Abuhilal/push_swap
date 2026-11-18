/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42amman.com>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-18 18:46:34 by mabuhila          #+#    #+#             */
/*   Updated: 2026-11-18 18:46:34 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_list *stack)
{
    long mistakes;
    long pairs;
    t_list *current;
    t_list *temp;

    mistakes = 0;
    pairs = 0;
    current = stack;
    while (current)
    {
        temp = current->next;
        while (temp)
        {
            if ((int)(intptr_t)current->content
            > (int)(intptr_t)temp->content)
                mistakes++;
            pairs++;
            temp = temp->next;
        }
        current = current->next;
    }
    if (pairs == 0)
        return (0.0);
    return ((double)mistakes / (double)pairs);
}