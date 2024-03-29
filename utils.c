/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:57:01 by tairribe          #+#    #+#             */
/*   Updated: 2023/08/19 13:59:54 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_mt(void **mt)
{
	int	i;

	i = 0;
	if (mt == NULL)
		return (i);
	while (mt[i])
		free(mt[i++]);
	free(mt);
	mt = NULL;
	return (i);
}

t_bool	is_str_int(char *str_nb)
{
	char	*max_int_str;
	int		max_len;
	int		len;
	long	nb;

	len = ft_strlen(str_nb);
	max_int_str = ft_itoa(INT_MAX);
	max_len = ft_strlen(max_int_str);
	free(max_int_str);
	if (str_nb[0] == '-')
		max_len++;
	if (len < max_len)
		return (true);
	if (len > max_len)
		return (false);
	nb = ft_strtol(str_nb);
	if (nb < INT_MIN || nb > INT_MAX)
		return (false);
	return (true);
}

t_push_swap	*init_push_swap(void)
{
	t_push_swap	*ps;

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

void	free_and_exit(t_push_swap *ps, int code)
{
	free_dcll(ps->stack_a);
	free_dcll(ps->stack_b);
	ft_lstclear(&ps->moves, free);
	ft_lstclear(&ps->moves_gt, free);
	free_mt((void **) ps->words);
	free(ps);
	exit(code);
}

void	error(t_push_swap *ps)
{
	ft_dprintf(2, "Error\n");
	free_and_exit(ps, 1);
}
