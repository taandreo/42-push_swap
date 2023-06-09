/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:49:13 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/13 00:06:29 by tairribe         ###   ########.fr       */
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
	int		nb;
	int		index;
	t_bool	keep_a;
}			t_cont;

typedef struct s_node
{
	t_cont          cont;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_dcll
{
	t_node	*head;
	t_node	*tail;
	t_node	*markup_head;
	char	markup_type;
	int		len;
}			t_dcll;

typedef struct s_push_swap
{
	t_dcll	*stack_a;
	t_dcll	*stack_b;
	t_list	*moves;
}			t_push_swap;

// linked_list.c
t_bool	is_new_dcll(t_dcll *dcll, int nb);
t_node	*new_node_back(t_dcll *dcll, int nb);
t_node	*new_node_front(t_dcll *dcll, int nb);
t_node	*add_node_back(t_dcll *dcll, t_node *node);
t_node	*add_node_front(t_dcll *dcll, t_node *node);
t_node	*del_node_front(t_dcll *dcll);
void	print_dcll(t_dcll *dcll);
void	free_dcll(t_dcll *dcll);
t_dcll	*copy_dcll(t_dcll *list);
// markup.c
void	set_best_index_markup(t_dcll *list);
int		set_index_markup(t_node *start);
void	set_best_gt_markup(t_dcll *list);
int		set_gt_markup(t_node *start);
// utils.c
int		free_mt(void **mt);
t_bool	is_str_int(char *str_nb);
void	free_and_exit(t_push_swap *ps, int code);
void	error(t_push_swap *ps);
// parse.c
void	parse_argv(t_dcll *stack, int argc, char *argv[]);
// moves.c
void	solve(t_push_swap *ps);

#endif