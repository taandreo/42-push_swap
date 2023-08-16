/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:31:52 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 21:35:27 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Doubly Circular Linked List struct*/
t_node	*add_node_back(t_dcll *dcll, t_node *node)
{
	if (dcll->head == NULL)
	{
		dcll->head = node;
		dcll->tail = node;
		node->next = node->prev = node;
	} else {
		dcll->tail->next = node;
		node->prev = dcll->tail;
		node->next = dcll->head;
		dcll->head->prev = node;
		dcll->tail = node;
	}
	dcll->len++;
	return node;
}

t_node	*new_node_back(t_dcll *dcll, int nb)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (NULL);
	node->cont.nb = nb;
	node->cont.index = -1;
	return(add_node_back(dcll, node));
}

t_node	*add_node_front(t_dcll *dcll, t_node *node)
{
	if (dcll->head == NULL)
	{
		dcll->head = node;
		dcll->tail = node;
		node->next = node->prev = node;
	} else {
		dcll->head->prev = node;
		node->prev = dcll->tail;
		node->next = dcll->head;
		dcll->tail->next = node;
		dcll->head = node;
	}
	dcll->len++;
	return node;
}

t_node	*new_node_front(t_dcll *dcll, int nb)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (NULL);
	node->cont.nb = nb;
	node->cont.index = -1;
	return(add_node_front(dcll, node));
}

t_node	*del_node_front(t_dcll *dcll)
{
	t_node *node;
	
	node = dcll->head;
	if (dcll->head == NULL)
		return (NULL);
	if (dcll->head == dcll->head->next)
	{
		dcll->head = NULL;
		dcll->tail = NULL;
		dcll->len--;
		return (node);
	}
	dcll->head = dcll->head->next;
	dcll->head->prev = dcll->tail;
	dcll->tail->next = dcll->head;
	dcll->len--;
	return (node);
}