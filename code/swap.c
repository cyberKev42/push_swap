/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:52:58 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:17:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first 2 elements of stack a
int	sa(t_data *data, int n)
{
	int	tmp;

	if (!data->a_col)
		return (1);
	if (!data->a_col->next)
		return (1);
	tmp = data->a_col->nbr;
	data->a_col->nbr = data->a_col->next->nbr;
	data->a_col->next->nbr = tmp;
	if (!n)
		ft_printf("sa\n");
	return (0);
}

//swap the first 2 elements of stack b
int	sb(t_data *data, int n)
{
	int	tmp;

	if (!data->b_col)
		return (1);
	if (!data->b_col->next)
		return (1);
	tmp = data->b_col->nbr;
	data->b_col->nbr = data->b_col->next->nbr;
	data->b_col->next->nbr = tmp;
	if (!n)
		ft_printf("sb\n");
	return (0);
}

int	ss(t_data *data)
{
	sa(data, 1);
	sb(data, 1);
	ft_printf("ss\n");
	return (0);
}
