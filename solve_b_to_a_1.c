/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b_to_a_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:12:59 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/20 18:11:54 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the ideal location for b_node in stack a. The ideal location will be*/
t_node	*find_a_node_for_b(t_dcll *stack, t_node *b_node)
{
	t_node		*a_node;

	a_node = stack->head;
	if (b_node->cont.index < a_node->cont.index)
	{
		while (b_node->cont.index < a_node->prev->cont.index
			&& a_node->cont.index > a_node->prev->cont.index)
			a_node = a_node->prev;
	}
	else
	{
		while (b_node->cont.index > a_node->cont.index
			&& a_node->cont.index < a_node->next->cont.index)
			a_node = a_node->next;
		if (b_node->cont.index > a_node->cont.index
			&& a_node->cont.index > a_node->next->cont.index)
			a_node = a_node->next;
	}
	return (a_node);
}

void	find_moves(int *r, int *rr, t_dcll *stack, t_node *src_node)
{
	t_node	*node;

	*r = 0;
	*rr = 0;
	node = src_node;
	while (node != stack->head)
	{	
		(*rr)++;
		node = node->next;
	}
	node = src_node;
	while (node != stack->head)
	{	
		(*r)++;
		node = node->prev;
	}
}

void	set_routes(t_routes *mv, char a_route, char b_route, int moves)
{
	mv->a_route = a_route;
	mv->b_route = b_route;
	mv->moves = moves;
}

/* Find the best possible movements for a specific node in the b stack*/
t_routes	*find_best_route(t_push_swap *ps, t_node *b_node)
{
	t_routes	*mv;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;

	mv = ft_calloc(sizeof(t_routes), 1);
	mv->b_node = b_node;
	mv->a_node = find_a_node_for_b(ps->stack_a, b_node);
	find_moves(&ra, &rra, ps->stack_a, mv->a_node);
	find_moves(&rb, &rrb, ps->stack_b, mv->b_node);
	set_routes(mv, 0, 0, ft_max(ra, rb));
	if (ft_max(rra, rrb) < mv->moves)
		set_routes(mv, 1, 1, ft_max(rra, rrb));
	if (ra + rrb < mv->moves)
		set_routes(mv, 0, 1, ra + rrb);
	if (rra + rb < mv->moves)
		set_routes(mv, 1, 0, rra + rb);
	return (mv);
}
