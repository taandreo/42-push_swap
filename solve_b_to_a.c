/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:59:50 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/08 00:55:36 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_routes {

	t_node	*a_node;
	t_node	*b_node;
	char	a_route;
	char	b_route;
	int		moves;
}	t_routes;

/* find the ideal location for b_node in stack a. The ideal location will be*/
t_node	*find_a_node_for_b(t_dcll *stack, t_node *b_node)
{
	t_node		*a_node;

	a_node = stack->head;
	if (b_node->cont.index < a_node->cont.index)
	{
		while (b_node->cont.index < a_node->prev->cont.index &&
			a_node->cont.index > a_node->prev->cont.index)
			a_node = a_node->prev;
	}
	else {
		while (b_node->cont.index > a_node->cont.index &&
			a_node->cont.index < a_node->next->cont.index){
			a_node = a_node->next;
			if (b_node->cont.index > a_node->cont.index &&
				a_node->cont.index > a_node->next->cont.index)
				a_node = a_node->next;
		}
	}
	return (a_node);
}

void	find_moves(int *r, int *rr, t_dcll *stack, t_node *src_node)
{
	*r = 0;
	*rr = 0;
	t_node *node;

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
		set_routes(mv, 1, 0, ra + rrb);
	return(mv);
}

void	print_routes(t_routes *routes)
{
	ft_printf("moves:   %i\n", routes->moves);
	ft_printf("a_node:  %i\n", routes->a_node->cont.index);
	ft_printf("b_node:  %i\n", routes->b_node->cont.index);
	ft_printf("a_route: %i\n", routes->b_route);
	ft_printf("b_route: %i\n", routes->a_route);
}

t_routes	*find_next_node(t_push_swap *ps)
{
	int			i;
	t_node		*node;
	t_routes	*route;
	t_routes    *best_route;

	i = 0;
	node = ps->stack_b->head;
	best_route = find_best_route(ps, node);
	while (i < ps->stack_b->len) 
	{
		node = node->next;
		route = find_best_route(ps, node);
		if (route->moves < best_route->moves)
		{
			free(best_route);
			best_route = route;
		} else {
			free(route);
		}
		node = node->next;
		i++;
	}
	return(best_route);
}

void	mv_node_b_to_a(t_push_swap *ps, t_routes *routes)
{
	if (routes->a_route == routes->b_route){
		while (routes->a_node != ps->stack_a->head &&
			routes->b_node != ps->stack_b->head)
		{
			if (routes->a_route == 0)
			{
				rx(ps->stack_a);
				rx(ps->stack_b);
				add_move(&ps->moves, "rr");
			} else {
				rrx(ps->stack_a);
				rrx(ps->stack_b);
				add_move(&ps->moves, "rrr");
			}
		}
	}
	while (routes->a_node != ps->stack_a->head)
	{
		if (routes->a_route == 0)
		{
			rx(ps->stack_a);
			add_move(&ps->moves, "ra");
		} else {
			rrx(ps->stack_a);
			add_move(&ps->moves, "rra");
		} 
	}
	while (routes->b_node != ps->stack_b->head)
	{
		if (routes->b_route == 0)
		{
			rx(ps->stack_b);
			add_move(&ps->moves, "rb");
		} else {
			rrx(ps->stack_b);
			add_move(&ps->moves, "rrb");
		} 
	}
}

void	solve_b_to_a(t_push_swap *ps)
{
	t_routes	*routes;
	
	while (ps->stack_b->len > 1){
		print_stacks(ps->stack_a, ps->stack_b);
		routes = find_next_node(ps);
		mv_node_b_to_a(ps, routes);
		push(ps->stack_b, ps->stack_a);
		add_move(&ps->moves, "pa");
	}
	print_stacks(ps->stack_a, ps->stack_b);
	push(ps->stack_b, ps->stack_a);
	add_move(&ps->moves, "pa");
	print_stacks(ps->stack_a, ps->stack_b);
}
