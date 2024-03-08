/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:57:24 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:31:46 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift up all elements of stack a by 1, first element becomes last
int	ra(t_data *data, int n)
{
	t_lst	*ptr;
	t_lst	*ptr_first;

	if (!data->a_col)
		return (1);
	if (!data->a_col->next)
		return (1);
	ptr = data->a_col;
	ptr_first = data->a_col;
	data->a_col = data->a_col->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ptr_first;
	ptr_first->next = NULL;
	if (!n)
		ft_printf("ra\n");
	return (0);
}

//shift up all elements of stack b by 1, first element becomes last
int	rb(t_data *data, int n)
{
	t_lst	*ptr;
	t_lst	*ptr_first;

	if (!data->b_col)
		return (1);
	if (!data->b_col->next)
		return (1);
	ptr = data->b_col;
	ptr_first = data->b_col;
	data->b_col = data->b_col->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ptr_first;
	ptr_first->next = NULL;
	if (!n)
		ft_printf("rb\n");
	return (0);
}

int	rr(t_data *data)
{
	ra(data, 1);
	rb(data, 1);
	ft_printf("rr\n");
	return (0);
}
