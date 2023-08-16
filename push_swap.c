/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:31 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 21:21:08 by tairribe         ###   ########.fr       */
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
	ps->moves = NULL;
	ps->moves_gt = NULL;
	return (ps);
}

void	gt_markup(t_push_swap *ps)
{
	index_list(ps->stack_a);
	set_best_gt_markup(ps->stack_a);
	solve(ps);
	ps->moves_gt = ps->moves;
	ps->moves = NULL;
	free_dcll(ps->stack_a);
	free_dcll(ps->stack_b);
	ps->stack_a = ft_calloc(sizeof(t_dcll), 1);
	ps->stack_b = ft_calloc(sizeof(t_dcll), 1);
}

void	index_markup(t_push_swap *ps)
{
	index_list(ps->stack_a);
	set_best_index_markup(ps->stack_a);
	solve(ps);
}

int	main(int argc, char *argv[])
{
	t_push_swap	*ps;
	
	if (argc < 2)
		return(0);
	
	ps = init_push_swap();
	parse_argv(ps, argc, argv);
	gt_markup(ps);
	parse_argv(ps, argc, argv);
	index_markup(ps);
	if (ft_lstsize(ps->moves_gt) <= ft_lstsize(ps->moves))
		print_moves(ps->moves_gt);
	else
		print_moves(ps->moves);
	free_and_exit(ps, 0);
}

