/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:06:23 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/15 21:54:20 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_push_swap *ps, char *str_nb)
{
	if (!ft_is_number(str_nb))
		error(ps);
	if (!is_str_int(str_nb))
		error(ps);
	if (is_new_dcll(ps->stack_a, ft_atoi(str_nb)))
		new_node_back(ps->stack_a, ft_atoi(str_nb));
	else
		error(ps);
}

void	parse_space(t_push_swap *ps, char *str)
{
	char	**words;
	int		i;

	words = ft_split(str, ' ');
	i = 0;
	while (words[i] != NULL)
		add_number(ps, words[i++]);
	free_mt((void **) words);
	if (i == 0)
		error(ps);
}

void	parse_argv(t_push_swap *ps, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			parse_space(ps, argv[i]);
		else
			add_number(ps, argv[i]);
		i++;
	}
}
