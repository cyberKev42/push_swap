/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:57:46 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift down all elements of stack a by 1, last element becomes first
int	rra(t_data *data, int n)
{
	t_lst	*ptr;
	t_lst	*ptr_last;

	if (!data->a_col->next)
		return (1);
	ptr = data->a_col;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr_last = ptr->next;
	ptr_last->next = data->a_col;
	data->a_col = ptr_last;
	ptr->next = NULL;
	if (!n)
		ft_printf("rra\n");
	return (0);
}

//shift down all elements of stack b by 1, last element becomes first
int	rrb(t_data *data, int n)
{
	t_lst	*ptr;
	t_lst	*ptr_last;

	if (!data->b_col->next)
		return (1);
	ptr = data->b_col;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr_last = ptr->next;
	ptr_last->next = data->b_col;
	data->b_col = ptr_last;
	ptr->next = NULL;
	if (!n)
		ft_printf("rrb\n");
	return (0);
}

int	rrr(t_data *data)
{
	rra(data, 1);
	rrb(data, 1);
	ft_printf("rrr\n");
	return (0);
}
