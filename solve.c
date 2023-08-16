/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:07:53 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 22:30:32 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align(t_push_swap *ps)
{
	int		r;
	int		rr;
	t_node	*node;

	node = ps->stack_a->head;
	while (node->cont.index != 0)
		node = node->next;
	find_moves(&r, &rr, ps->stack_a, node);
	if (r <= rr)
	{
		while (ps->stack_a->head->cont.index != 0)
		{
			rx(ps->stack_a);
			add_move(&ps->moves, "ra");
		}		
	}
	else
	{
		while (ps->stack_a->head->cont.index != 0)
		{
			rrx(ps->stack_a);
			add_move(&ps->moves, "rra");
		}
	}
}

void	solve(t_push_swap *ps)
{
	solve_a_to_b(ps);
	solve_b_to_a(ps);
	align(ps);
}
