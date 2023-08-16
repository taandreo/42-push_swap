/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:49:13 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 22:18:02 by tairribe         ###   ########.fr       */
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
	t_list  *moves_gt;
}			t_push_swap;

typedef struct s_routes {

	t_node	*a_node;
	t_node	*b_node;
	char	a_route;
	char	b_route;
	int		moves;
}			t_routes;

// stack_0.c
t_node	*new_node_back(t_dcll *dcll, int nb);
t_node	*new_node_front(t_dcll *dcll, int nb);
t_node	*add_node_back(t_dcll *dcll, t_node *node);
t_node	*add_node_front(t_dcll *dcll, t_node *node);
t_node	*del_node_front(t_dcll *dcll);
// stack_1.c
t_bool	is_new_dcll(t_dcll *dcll, int nb);
void	free_dcll(t_dcll *dcll);
// index.c
void	index_list(t_dcll *list);
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
void	parse_argv(t_push_swap *ps, int argc, char *argv[]);
// moves.c
void	rrx(t_dcll *stack);
void	rx(t_dcll *stack);
void	push(t_dcll *stack_1, t_dcll *stack_2);
void	swap(t_dcll	*stack);
void	add_move(t_list **moves, char *move);
// moves2.c
void	move(t_push_swap *ps, char *move);
// solve_b_to_a_1.c
t_routes	*find_best_route(t_push_swap *ps, t_node *b_node);
// solve_b_to_a_0.c
void	solve_b_to_a(t_push_swap *ps);
void	find_moves(int *r, int *rr, t_dcll *stack, t_node *src_node);
// solve_a_to_b.c
void	solve_a_to_b(t_push_swap *ps);
// solve.c
void	solve(t_push_swap *ps);
// prints.c
void	print_routes(t_routes *routes);
void	print_moves(t_list *moves);
void	print_stacks(t_dcll *stack_a, t_dcll *stack_b);


#endif