/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:24:00 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/20 19:21:54 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_move(t_push_swap *ps, char *m)
{
	if (ft_strcmp(m, "ra") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "rb") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "rra") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "rrb") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "rr") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "rrr") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "sa") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "sb") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "pa") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "pb") == 0)
		move(ps, m);
	else if (ft_strcmp(m, "ss") == 0)
		move(ps, m);
	else
		error(ps);
}

void	read_moves(t_push_swap *ps)
{
	char	*line;
	char	*move;

	line = get_next_line(0);
	while (line)
	{
		move = ft_strtrim(line, "\n");
		free(line);
		apply_move(ps, move);
		free(move);
		line = get_next_line(0);
	}
}

void	print_and_exit(t_push_swap *ps, char *m)
{
	ft_printf("%s\n", m);
	free_and_exit(ps, 0);
}

void	check(t_push_swap *ps)
{
	t_node	*node;

	if (ps->stack_b->head != NULL)
		print_and_exit(ps, "KO");
	node = ps->stack_a->head;
	while (node != ps->stack_a->tail)
	{
		if (node->cont.nb > node->next->cont.nb)
			print_and_exit(ps, "KO");
		node = node->next;
	}
	print_and_exit(ps, "OK");
}

int	main(int argc, char *argv[])
{
	t_push_swap	*ps;

	if (argc < 2)
		return (0);
	ps = init_push_swap();
	parse_argv(ps, argc, argv);
	read_moves(ps);
	check(ps);
}
