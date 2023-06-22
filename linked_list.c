/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:13:43 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/22 00:43:12 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Doubly Circular Linked List struct*/
void	new_node_back(int nb, t_dcll *dcll)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return ;
	node->cont.nb = nb;
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
}

void	new_node_front(int nb, t_dcll *dcll)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return ;
	node->cont.nb = nb;
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
}

void	print_dcll(t_dcll *dcll)
{
	t_node *tmp;
	if (dcll->head == NULL)
		return ;
	
	tmp = dcll->head;
	while (tmp != dcll->tail)
	{
		ft_printf("[%d] ", tmp->cont.nb);
		tmp = tmp->next;
	}
	ft_printf("[%d]\n", tmp->cont.nb);
}

void	free_dcll(t_dcll *dcll)
{
	t_node *node;
	t_node *tmp;

	if (dcll == NULL)
		return ;
	if (dcll->len == 0)
	{
		free(dcll);
		return ;
	}
	node = dcll->head;
	while (node != dcll->tail)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(node);
	free(dcll);
}

char	is_new_dcll(t_dcll *dcll, int nb)
{
	t_node *tmp;
	if (dcll->len == 0)
		return (1);
	
	tmp = dcll->head;
	while (tmp != dcll->tail)
	{
		if (tmp->cont.nb == nb)
			return (0);
	}
	if (tmp->cont.nb == nb)
		return (0);
	return (1);
}
