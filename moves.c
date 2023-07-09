/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:17:29 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/09 14:55:23 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* change the content two nodes in sequence for a Doubly Circular Linked List.*/
void	swap_cont(t_node *a, t_node *b)
{
	t_cont	swap;

	swap = a->cont;
	a->cont = b->cont;
	b->cont = swap;
}

t_bool check_false(t_dcll *stack)
{
	t_node *node;
	
	while(true)
    {
		if (node->cont.keep_a)
        if (node == stack->tail)
            break;
        node = node->next;
    }
}

void	solve(t_dcll *stack)
{
	t_dcll	*stack_b;

	stack_b = ft_calloc(sizeof(t_dcll), 1);
	look_false()
	while (look_false())
}