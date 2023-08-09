/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:01:03 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/08 22:19:49 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_list **moves, char *move)
{
	t_list *node;
	
	node = ft_lstnew((char *) ft_strdup(move));
	ft_lstadd_back(moves, node);
}

void 	move(t_push_swap *ps, char *move)
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
	add_move(&ps->moves, move);
}
