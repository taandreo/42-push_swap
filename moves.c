/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:17:29 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/08 22:20:52 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* change the content two nodes in sequence for a Doubly Circular Linked List.*/
void	swap(t_dcll	*stack)
{
	t_cont	swap;
	t_node	*a;
	t_node	*b;

	a = stack->head;
	b = stack->head->next;
	swap = a->cont;
	a->cont = b->cont;
	b->cont = swap;
}

void	push(t_dcll *stack_1, t_dcll *stack_2)
{
	if (stack_1->head == NULL)
		return ;
	add_node_front(stack_2, del_node_front(stack_1));
}

void	rx(t_dcll *stack)
{
	t_node	*tmp;
	
	if (stack->head == NULL)
		return ;
	if (stack->head == stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->tail = tmp;
	stack->tail->next = stack->head;
}

void	rrx(t_dcll *stack)
{	
	if (stack->head == NULL)
		return ;
	if (stack->head == stack->head->next)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->head->prev;
}

void	print_moves(t_list *moves)
{
	t_list	*node;
	
	if (!moves)
		return ;
	node = moves;
	ft_printf("moves: ");
	while (node)
	{
		ft_printf("%s ", node->content);
		node = node->next;
	}
	ft_printf("\n");
}
