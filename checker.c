/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:24:00 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/17 20:37:42 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap *init_push_swap(void)
{
	t_push_swap *ps;

	ps = ft_calloc(sizeof(t_push_swap), 1);
	if (ps == NULL)
		return (NULL);
	ps->stack_a = ft_calloc(sizeof(t_dcll), 1);
	ps->stack_b = ft_calloc(sizeof(t_dcll), 1);
	ps->moves = NULL;
	ps->moves_gt = NULL;
	ps->words = NULL;
	return (ps);
}

int main(int argc, char *argv[])
{
	t_push_swap *ps;
	char 		*line;

	if (argc < 2)
		return (0);
	ps = init_push_swap();
	parse_argv(ps, argc, argv);
	line = get_next_line(0);
	while(line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
}