/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:49:54 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/29 23:37:57 by tairribe         ###   ########.fr       */
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
	node = node->next;
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
	start->cont.keep_a_index = true;
	node  = start->next;
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
	return (index - start->cont.index + 1);
}

void	set_best_gt_markup(t_dcll *list)
{
	t_node	*keep_a_node_max;
	t_node	*node;
	int		keep_a_max;
	int 	keep_a;

	node = list->head;
	keep_a_max = set_gt_markup(node);
	keep_a_node_max = node;
	node = node->next;
	while(node != list->head)
	{	
		keep_a = set_gt_markup(node);
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
	set_gt_markup(keep_a_node_max);
}

int	set_gt_markup(t_node *start)
{
	t_node	*node;
	int		nb;
	int		i;

	nb = start->cont.nb;
	start->cont.keep_a_gt = true;
	node  = start->next;
	i = 1;
	while(node != start)
	{
		if (node->cont.nb > nb)
		{
			node->cont.keep_a_gt = true;
			nb = node->cont.nb;
			i++;
		}
		else 
			node->cont.keep_a_gt = false;
		node = node->next;
	}
	return (i);
}