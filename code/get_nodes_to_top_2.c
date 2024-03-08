/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes_to_top_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:15:40 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nodes_to_top_2(t_data *data, t_lst *ptr_first, t_lst *ptr_second)
{
	t_lst	*ptr_l;
	t_lst	*ptr1;
	t_lst	*ptr2;

	ptr1 = ptr_first;
	ptr2 = ptr_second;
	ptr_l = ptr1;
	while (ptr_l->lowest_cost == 0)
		ptr_l = ptr_l->next;
	while (ptr1->lowest_cost != 1 || ptr2 != ptr1->target_nbr)
	{
		if (!rotate_up_down_2(data, ptr_l, ptr1, ptr2))
			rotate_ud_du_2(data, ptr_l, ptr1, ptr2);
		ptr1 = data->b_col;
		ptr2 = data->a_col;
	}
	return (0);
}

int	rotate_up_down_2(t_data *data, t_lst *ptr, t_lst *ptr1, t_lst *ptr2)
{
	if (ptr->first_half && ptr->target_nbr->first_half)
	{
		if (ptr1 != ptr && ptr2 != ptr->target_nbr)
			rr(data);
		else if (ptr1 == ptr && ptr2 != ptr->target_nbr)
			ra(data, 0);
		else if (ptr1 != ptr && ptr2 == ptr->target_nbr)
			rb(data, 0);
		return (1);
	}
	if (!ptr->first_half && !ptr->target_nbr->first_half)
	{
		if (ptr1 != ptr && ptr2 != ptr->target_nbr)
			rrr(data);
		else if (ptr1 == ptr && ptr2 != ptr->target_nbr)
			rra(data, 0);
		else if (ptr1 != ptr && ptr2 == ptr->target_nbr)
			rrb(data, 0);
		return (1);
	}
	return (0);
}

int	rotate_ud_du_2(t_data *data, t_lst *ptr, t_lst *ptr1, t_lst *ptr2)
{
	if (ptr->first_half && !ptr->target_nbr->first_half)
	{
		if (ptr1 != ptr && ptr2 != ptr->target_nbr)
		{
			rb(data, 0);
			rra(data, 0);
		}
		else if (ptr1 == ptr && ptr2 != ptr->target_nbr)
			rra(data, 0);
		else if (ptr1 != ptr && ptr2 == ptr->target_nbr)
			rb(data, 0);
	}
	if (!ptr->first_half && ptr->target_nbr->first_half)
	{
		if (ptr1 != ptr && ptr2 != ptr->target_nbr)
		{
			rrb(data, 0);
			ra(data, 0);
		}
		else if (ptr1 == ptr && ptr2 != ptr->target_nbr)
			ra(data, 0);
		else if (ptr1 != ptr && ptr2 == ptr->target_nbr)
			rrb(data, 0);
	}
	return (0);
}
