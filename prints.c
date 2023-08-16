/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:58:28 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 21:18:18 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_routes(t_routes *routes)
{
	ft_printf("moves:   %i\n", routes->moves);
	ft_printf("a_node:  %i\n", routes->a_node->cont.index);
	ft_printf("b_node:  %i\n", routes->b_node->cont.index);
	ft_printf("a_route: %i\n", routes->b_route);
	ft_printf("b_route: %i\n", routes->a_route);
}

void	print_stack(t_dcll *dcll)
{
	char	*keep_a;
	// char	*keep_a_gt;
	t_node 	*tmp;
	if (dcll->head == NULL)
		return ;

	tmp = dcll->head;
	while (true)
	{
		if (tmp->cont.keep_a == true)
			keep_a = "true";
		else
			keep_a = "false";
		ft_printf("[%d] [%d] [%s]\n", tmp->cont.nb, tmp->cont.index, keep_a);
		if (tmp == dcll->tail)
			break;
		tmp = tmp->next;
	}
}

void	print_stacks(t_dcll *stack_a, t_dcll *stack_b)
{
	ft_printf("STACK A:\n");
	print_stack(stack_a);
	ft_printf("\n");
	ft_printf("STACK B:\n");
	print_stack(stack_b);
	ft_printf("--------------------------\n");
}

void	print_moves(t_list *moves)
{
	t_list	*node;
	
	if (!moves)
		return ;
	node = moves;
	while (node)
	{
		ft_printf("%s\n", node->content);
		node = node->next;
	}
}

void	print_moves_inline(t_list *moves)
{
	t_list	*node;
	
	if (!moves)
		return ;
	node = moves;
	while (node)
	{
		ft_printf("%s ", node->content);
		node = node->next;
	}
	ft_printf("\n");
}