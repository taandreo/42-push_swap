/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:57:01 by tairribe          #+#    #+#             */
/*   Updated: 2023/06/22 23:29:13 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_mt(void **mt)
{
	int	i;

	i = 0;
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
		return false;
	return true;
}