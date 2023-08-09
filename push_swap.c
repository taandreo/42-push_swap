/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:31 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/08 23:14:35 by tairribe         ###   ########.fr       */
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

t_push_swap	*init_push_swap()
{
	t_push_swap	*ps;

	ps = ft_calloc(sizeof(t_push_swap), 1);
	if (ps == NULL)
		return NULL;
	ps->stack_a = ft_calloc(sizeof(t_dcll), 1);
	ps->stack_b = ft_calloc(sizeof(t_dcll), 1);
	return (ps);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*ps;
	
	if (argc < 2)
		return(0);
	ps = init_push_swap();
	parse_argv(ps, argc, argv);
	index_list(ps->stack_a);
	// set_best_index_markup(ps->stack_a);
	set_best_gt_markup(ps->stack_a);
	ft_printf("\n\n");
	solve(ps);
	free_and_exit(ps, 0);
}

