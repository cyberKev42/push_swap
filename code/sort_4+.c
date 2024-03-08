/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4+.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:51:00 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_4plus(t_data *data)
{
	push_to_b(data);
	sort_3(data);
	push_to_a(data);
	sort_a(data, data->a_col);
	return (0);
}

int	push_to_b(t_data *data)
{
	t_lst	*ptr1;
	t_lst	*ptr2;

	pb(data);
	ptr1 = data->a_col;
	if (ptr1->next->next->next != 0)
		pb(data);
	ptr1 = data->a_col;
	ptr2 = data->b_col;
	while (ptr1->next->next->next != 0)
	{
		define_all_targets_for_a(data, ptr1, ptr2);
		define_all_costs(ptr1, ptr2);
		get_nodes_to_top(data, ptr1, ptr2);
		pb(data);
		ptr1 = data->a_col;
		ptr2 = data->b_col;
	}
	return (0);
}

int	push_to_a(t_data *data)
{
	t_lst	*ptr1;
	t_lst	*ptr2;

	ptr1 = data->b_col;
	ptr2 = data->a_col;
	while (ptr1 != 0)
	{
		define_all_targets_for_b(data, ptr1, ptr2);
		define_all_costs(ptr1, ptr2);
		get_nodes_to_top_2(data, ptr1, ptr2);
		pa(data);
		ptr1 = data->b_col;
		ptr2 = data->a_col;
	}
	return (0);
}

void	sort_a(t_data *data, t_lst *ptr_a)
{
	int		lowest_nbr;
	t_lst	*ptr_lowest;

	set_index(ptr_a, data->b_col);
	lowest_nbr = 2147483647;
	while (ptr_a)
	{
		if (ptr_a->nbr < lowest_nbr)
		{
			ptr_lowest = ptr_a;
			lowest_nbr = ptr_a->nbr;
		}
		ptr_a = ptr_a->next;
	}
	if (ptr_lowest->index < ft_lstsize_utils(data->a_col) / 2)
	{
		while (ptr_lowest != data->a_col)
			ra(data, 0);
	}
	else
	{
		while (ptr_lowest != data->a_col)
			rra(data, 0);
	}
}
