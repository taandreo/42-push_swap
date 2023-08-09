/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:01:03 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/08 22:29:14 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_list **moves, char *move)
{
	t_list *node;
	
	node = ft_lstnew((char *) ft_strdup(move));
	ft_lstadd_back(moves, node);
}

void 	rotate(t_push_swap *ps, char *move)
{
	if (ft_strncmp(move, "ra", 3) == 0)
		rx(ps->stack_a);
	if (ft_strncmp(move, "rb", 3) == 0)
		rx(ps->stack_b);
	if (ft_strncmp(move, "rra", 3) == 0)
		rrx(ps->stack_a);
	if (ft_strncmp(move, "rrb", 3) == 0)
		rrx(ps->stack_b);
	if (ft_strncmp(move, "rr", 3) == 0)
	{
		rx(ps->stack_a);
		rx(ps->stack_b);
	}
	if (ft_strncmp(move, "rrr", 3) == 0)
	{
		rrx(ps->stack_a);
		rrx(ps->stack_b);
	}
}

void	move(t_push_swap *ps, char *move)
{
	if (move[0] == 'r')
		rotate(ps, move);
	if (ft_strncmp(move, "sa", 3) == 0)
		swap(ps->stack_a);
	if (ft_strncmp(move, "sb", 3) == 0)
		swap(ps->stack_b);
	if (ft_strncmp(move, "pa", 3) == 0)
		push(ps->stack_b, ps->stack_a);
	if (ft_strncmp(move, "pb", 3) == 0)
		push(ps->stack_a, ps->stack_b);
	add_move(&ps->moves, move);
}