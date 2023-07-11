/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:17:29 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/11 01:41:54 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* change the content two nodes in sequence for a Doubly Circular Linked List.*/
void	swap(t_dcll	*stack)
{
	t_cont	swap;
	t_node	*a;
	t_node	*b;

	a = stack->head;
	b = stack->head->next;
	swap = a->cont;
	a->cont = b->cont;
	b->cont = swap;
}

t_bool check_false(t_dcll *stack)
{
	t_node *node;

	node = stack->head;
	while(true)
    {
		if (node->cont.keep_a == false)
			return (true);
        if (node == stack->tail)
            break;
        node = node->next;
    }
	return (false);
}

int	get_true(t_dcll *stack)
{
	int	i;
	t_node *node;

	node = stack->head;
	while(true)
    {
		if (node->cont.keep_a == true)
			i++;
        if (node == stack->tail)
            break;
        node = node->next;
    }
	return (i);
}



t_bool	check_and_swap(t_dcll	*stack_a)
{
	int	trues_before;

	trues_before = get_true(stack_a);
	swap(stack_a);
	if (stack_a->markup_type == 0)
	{
		set_gt_markup(stack_a->markup_head);
		if (get_true(stack_a) > trues_before)
			return (true);
		swap(stack_a);
		set_gt_markup(stack_a);
	}
	else
	{
		set_index_markup(stack_a->markup_head);
		if (get_true(stack_a) > trues_before)
			return (true);
		swap(stack_a);
		set_index_markup(stack_a);
	}
	return (false);
}

void	solve(t_dcll *stack_a)
{
	t_dcll	*stack_b;
	t_bool	swap;

	stack_b = ft_calloc(sizeof(t_dcll), 1);
	while (check_false(stack_a))
	{
		if (check_and_swap(stack_a))
			continue ;
		else if (stack_a->head->cont.keep_a == false)
			push(stack_a, stack_b);
		else
			rotate(stack_a);
	}	
}