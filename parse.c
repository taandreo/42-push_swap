/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:06:23 by tairribe          #+#    #+#             */
/*   Updated: 2023/07/09 12:07:40 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_dcll *dcll, char *str_nb)
{
	if (!ft_is_number(str_nb))
		error(dcll);
	if (!is_str_int(str_nb))
		error(dcll);
	if (is_new_dcll(dcll, ft_atoi(str_nb)))
		new_node_back(dcll, ft_atoi(str_nb));
	else
		error(dcll);
}

void	parse_space(t_dcll *dcll, char *str)
{
	char	**words;
	int		i;

	words = ft_split(str, ' ');
	i = 0;
	while (words[i] != NULL)
		add_number(dcll, words[i++]);
	free_mt((void **) words);
	if (i == 0)
		error(dcll);
}

t_dcll	*parse_argv(int argc, char *argv[])
{
	int 	i;
	t_dcll	*dcll;

	dcll = ft_calloc(sizeof(t_dcll), 1);
	i = 1;
	while(i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			parse_space(dcll, argv[i]);
		else
			add_number(dcll, argv[i]);
		i++;
	}
	return dcll;
}