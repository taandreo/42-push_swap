/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:31 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/09 19:08:38 by tairribe         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_dcll	*stack_a;
	
	if (argc < 2)
		return(0);
	stack_a = parse_argv(argc, argv);
	index_list(stack_a);
	// copy_dcll(stack_a);
	// set_best_index_markup(stack_a);
	set_best_gt_markup(stack_a);
	print_dcll(stack_a);
	solve(stack_a);
	print_dcll(stack_a);
	free_dcll(stack_a);
}

