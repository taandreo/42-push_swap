/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:57:52 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/08 21:09:57 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 0;
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

t_bool	check_and_swap(t_dcll *stack_a)
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
		set_gt_markup(stack_a->markup_head);
	}
	else
	{
		set_index_markup(stack_a->markup_head);
		if (get_true(stack_a) > trues_before)
			return (true);
		swap(stack_a);
		set_index_markup(stack_a->markup_head);
	}
	return (false);
}

void	solve_a_to_b(t_push_swap *ps)
{
	while (check_false(ps->stack_a))
	{
		if (check_and_swap(ps->stack_a))
			add_move(&ps->moves, "sa");
		else if (ps->stack_a->head->cont.keep_a == false)
		{
			add_move(&ps->moves, "pb");
			push(ps->stack_a, ps->stack_b);
		}
		else
		{
			add_move(&ps->moves, "ra");
			rx(ps->stack_a);
		}
	}
}

