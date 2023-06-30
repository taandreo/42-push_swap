/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:31 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/29 22:07:34 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_dcll *dcll, int code)
{
	free_dcll(dcll);
	exit(code);
}

void	error(t_dcll *dcll)
{
	ft_dprintf(2, "Error\n");
	free_and_exit(dcll, 1);
}

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

t_node	*get_min_stack(t_dcll *list)
{
	int		i;
	t_node	*node;
	t_node	*min;

	i = 0;
	min = NULL;
	node = list->head;
	while (i < list->len)
	{
		if (node->cont.index == -1)
		{
			if(min == NULL)
				min = node;
			else {
				if (node->cont.nb < min->cont.nb)
					min = node;
			}
		}
		i++;
		node = node->next;
	}
	return min;
}

void	index_list(t_dcll *list)
{
	t_node	*node;
	int		index;

	node = NULL;
	index = 0;
	while(index < list->len)
	{
		node = get_min_stack(list);
		node->cont.index = index;
		index++;
	}
}



int	main(int argc, char *argv[])
{
	t_dcll	*stack_a;
	
	if (argc < 2)
		return(0);
	stack_a = parse_argv(argc, argv);
	index_list(stack_a);
	set_best_index_markup(stack_a);
	print_dcll(stack_a);
	free_dcll(stack_a);
}

