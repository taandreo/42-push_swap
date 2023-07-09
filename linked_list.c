/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:13:43 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/09 15:49:55 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Doubly Circular Linked List struct*/
t_node	*new_node_back(t_dcll *dcll, int nb)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return ;
	node->cont.nb = nb;
	node->cont.index = -1;
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

t_node	*new_node_front(t_dcll *dcll, int nb)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return ;
	node->cont.nb = nb;
	node->cont.index = -1;
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

void	print_dcll(t_dcll *dcll)
{
	char	*keep_a_index;
	char	*keep_a_gt;
	t_node 	*tmp;
	if (dcll->head == NULL)
		return ;

	tmp = dcll->head;
	while (true)
	{
		if (tmp->cont.keep_a_index == true)
			keep_a_index = "true";
		else
			keep_a_index = "false";
		if (tmp->cont.keep_a_gt == true)
			keep_a_gt = "true";
		else
			keep_a_gt = "false";
		ft_printf("[%d] [%d] [%s] [%s]\n", tmp->cont.nb, tmp->cont.index, keep_a_index, keep_a_gt);
		if (tmp == dcll->tail)
			break;
		tmp = tmp->next;
	}
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

t_bool	is_new_dcll(t_dcll *dcll, int nb)
{
	t_node *tmp;
	if (dcll->len == 0)
		return (1);
	
	tmp = dcll->head;
	while (tmp != dcll->tail)
	{
		if (tmp->cont.nb == nb)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->cont.nb == nb)
		return (0);
	return (1);
}

t_dcll	*copy_dcll(t_dcll *list)
{
	t_dcll	*copy;
	t_node	*node;
	t_node	*copy_node;
	
	copy = ft_calloc(sizeof(t_dcll), 1);
	while(true)
    {
		copy_node = new_node_back(copy, node->cont.nb);
		copy_node->cont.index = node->cont.index;
        if (node == list->tail)
            break;
        node = node->next;
    }
	return copy;
}