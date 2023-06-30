/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:49:54 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/29 22:06:42 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_best_index_markup(t_dcll *list)
{
	t_node	*keep_a_node_max;
	t_node	*node;
	int		keep_a_max;
	int 	keep_a;

	node = list->head;
	keep_a_max = set_index_markup(node);
	keep_a_node_max = node;
	while(node != list->head)
	{	
		keep_a = set_index_markup(node);
		if (keep_a > keep_a_max)
		{
			keep_a_node_max = node;
			keep_a_max = keep_a;
		}
		if (keep_a == keep_a_max)
		{
			if (node->cont.index < keep_a_node_max->cont.index)
				keep_a_node_max = node;
		}
		node = node->next;
	}
	set_index_markup(keep_a_node_max);
}

int	set_index_markup(t_node *start)
{
	t_node	*node;
	int		index;

	index = start->cont.index;
	node = start->next;

	while(node != start)
	{
		if (node->cont.index == index + 1)
		{
			node->cont.keep_a_index = true;
			index++;
		}
		else 
			node->cont.keep_a_index = false;
		node = node->next;
		
	}
	return (index - start->cont.index);
}