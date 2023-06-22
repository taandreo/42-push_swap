/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:29:31 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/22 00:49:16 by tairribe         ###   ########.fr       */
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
		// if (ft_strchr(argv[i], ' '))
		// 	parse_space(argv[i], )
		// else ()
		if (ft_is_number(argv[i]) == 0)
			error(dcll);
		if (is_new_dcll(dcll, ft_atoi(argv[i])) == 1)
			new_node_back(ft_atoi(argv[i]), dcll);
		else
		{
			ft_printf("is new\n");
			error(dcll);
		}
	}
	print_dcll(dcll);
	free_dcll(dcll);
}

