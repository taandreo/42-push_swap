/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:49:13 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/22 23:21:34 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <limits.h>
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
t_bool	is_new_dcll(t_dcll *dcll, int nb);
void	new_node_back(t_dcll *dcll, int nb);
void	new_node_front(t_dcll *dcll, int nb);
void	print_dcll(t_dcll *dcll);
void	free_dcll(t_dcll *dcll);

// utils.c
int		free_mt(void **mt);
t_bool	is_str_int(char *str_nb);

#endif