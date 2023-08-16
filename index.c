/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:41:52 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 21:43:52 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_min_stack(t_dcll *list)
{
	int		i;
	t_node	*node;
	t_node	*min;

	i = 0;
	min = NULL;
	node = list->head;
	while (i < list->len)
	{
		if (node->cont.index == -1)
		{
			if(min == NULL)
				min = node;
			else {
				if (node->cont.nb < min->cont.nb)
					min = node;
			}
		}
		i++;
		node = node->next;
	}
	return min;
}

void	index_list(t_dcll *list)
{
	t_node	*node;
	int		index;

	node = NULL;
	index = 0;
	while(index < list->len)
	{
		node = get_min_stack(list);
		node->cont.index = index;
		index++;
	}
}