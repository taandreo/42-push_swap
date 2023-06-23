/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:31 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/22 21:32:31 by tairribe         ###   ########.fr       */
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

void	parse_space(t_dcll *dcll, char *str)
{
	char	**words;
	int		i;

	words = ft_split(str, ' ');
	i = 0;
	while (words[i] != NULL)
	{
		if(ft_is_number(words[i]) == 1)
			new_node_back(dcll, ft_atoi(words[i]));
		else
			error(dcll);
		i++;
	}
	free_mt((void **) words);
}

int	main(int argc, char *argv[])
{
	int i;
	t_dcll	*dcll;
	
	if (argc < 2)
		return(0);
	
	dcll = ft_calloc(sizeof(t_dcll), 1);
	dcll->len = 0;
	i = 1;
	while(i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			parse_space(dcll, argv[i]);
			i++;
			continue;
		}
		if (ft_is_number(argv[i]) == 0)
			error(dcll);
		if (is_new_dcll(dcll, ft_atoi(argv[i])) == 1)
			new_node_back(dcll, ft_atoi(argv[i]));
		else
			error(dcll);
		i++;
	}
	print_dcll(dcll);
	free_dcll(dcll);
}

