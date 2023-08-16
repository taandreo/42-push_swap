/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b_to_a_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:59:50 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 22:25:28 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_routes	*find_next_node(t_push_swap *ps)
{
	int			i;
	t_node		*node;
	t_routes	*route;
	t_routes	*best_route;

	i = 1;
	node = ps->stack_b->head;
	best_route = find_best_route(ps, node);
	node = node->next;
	while (i < ps->stack_b->len)
	{
		route = find_best_route(ps, node);
		if (route->moves < best_route->moves)
		{
			free(best_route);
			best_route = route;
		}
		else
			free(route);
		node = node->next;
		i++;
	}
	return (best_route);
}

void	mv_node_b_to_a(t_push_swap *ps, t_routes *routes)
{
	if (routes->a_route == routes->b_route)
	{
		while (routes->a_node != ps->stack_a->head
			&& routes->b_node != ps->stack_b->head)
		{
			if (routes->a_route == 0)
				move(ps, "rr");
			else
				move(ps, "rrr");
		}
	}
	while (routes->a_node != ps->stack_a->head)
	{
		if (routes->a_route == 0)
			move(ps, "ra");
		else
			move(ps, "rra");
	}
	while (routes->b_node != ps->stack_b->head)
	{
		if (routes->b_route == 0)
			move(ps, "rb");
		else
			move(ps, "rrb");
	}
}

void	solve_b_to_a(t_push_swap *ps)
{
	t_routes	*routes;

	while (ps->stack_b->len > 0)
	{
		routes = find_next_node(ps);
		mv_node_b_to_a(ps, routes);
		free(routes);
		move(ps, "pa");
	}
}
