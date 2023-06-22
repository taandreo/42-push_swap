/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:49:13 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/22 00:29:33 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef	struct	s_cont
{
	int	nb;
}		t_cont;

typedef struct s_node
{
	t_cont          cont;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_dcll
{
	t_node *head;
	t_node *tail;
	int		len;
}			t_dcll;

// linked_list.c
void	new_node_back(int nb, t_dcll *dcll);
void	new_node_front(int nb, t_dcll *dcll);
char	is_new_dcll(t_dcll *dcll, int nb);
void	print_dcll(t_dcll *dcll);
void	free_dcll(t_dcll *dcll);

#endif