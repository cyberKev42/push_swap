/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:56:51 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:57 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//push first element from stack b to top of stack a
int	pa(t_data *data)
{
	t_lst	*ptr;

	if (!data->b_col)
		return (1);
	ptr = data->b_col;
	data->b_col = data->b_col->next;
	ptr->next = data->a_col;
	data->a_col = ptr;
	ft_printf("pa\n");
	return (0);
}

//push first element from stack a to top of stack b
int	pb(t_data *data)
{
	t_lst	*ptr;

	if (!data->a_col)
		return (1);
	ptr = data->a_col;
	data->a_col = data->a_col->next;
	ptr->next = data->b_col;
	data->b_col = ptr;
	ft_printf("pb\n");
	return (0);
}
