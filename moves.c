/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:17:29 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:11 by tairribe         ###   ########.fr       */
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

void	rotate(t_dcll *stack)
{
	t_node	*tmp;
	
	if (stack->head == NULL)
		return ;
	if (stack->head == stack->head->next)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	// stack->head->prev = tmp;
	// stack->tail->next = tmp;
	stack->tail = tmp;
	stack->tail->next = stack->head;
}

t_bool check_false(t_dcll *stack)
{
	t_node *node;

	node = stack->head;
	while(true)
    {
		if (node->cont.keep_a == false)
			return (true);
        if (node == stack->tail)
            break;
        node = node->next;
    }
	return (false);
}

int	get_true(t_dcll *stack)
{
	int	i;
	t_node *node;

	i = 0;
	node = stack->head;
	while(true)
    {
		if (node->cont.keep_a == true)
			i++;
        if (node == stack->tail)
            break;
        node = node->next;
    }
	return (i);
}

t_bool	check_and_swap(t_dcll	*stack_a)
{
	int	trues_before;

	trues_before = get_true(stack_a);
	swap(stack_a);
	if (stack_a->markup_type == 0)
	{
		set_gt_markup(stack_a->markup_head);
		if (get_true(stack_a) > trues_before)
			return (true);
		swap(stack_a);
		set_gt_markup(stack_a->markup_head);
	}
	else
	{
		set_index_markup(stack_a->markup_head);
		if (get_true(stack_a) > trues_before)
			return (true);
		swap(stack_a);
		set_index_markup(stack_a->markup_head);
	}
	return (false);
}


void	add_move(t_list **moves, char *move)
{
	t_list *node;
	
	node = ft_lstnew((char *) ft_strdup(move));
	ft_lstadd_back(moves, node);
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

void	solve(t_push_swap *ps)
{
	while (check_false(ps->stack_a))
	{
		if (check_and_swap(ps->stack_a))
			add_move(&ps->moves, "sa");
		else if (ps->stack_a->head->cont.keep_a == false)
		{
			add_move(&ps->moves, "pb");
			push(ps->stack_a, ps->stack_b);
		}
		else
		{
			add_move(&ps->moves, "ra");
			rotate(ps->stack_a);
		}
	}
	print_moves(ps->moves);
}