/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:47:20 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_data *data, t_lst *ptr_a)
{
	t_lst	*ptr_b;

	ptr_b = data->b_col;
	ptr_a->target_nbr = NULL;
	while (ptr_b)
	{
		if (ptr_a->target_nbr)
		{
			if (ptr_b->nbr < ptr_a->nbr && ptr_a->target_nbr->nbr < ptr_b->nbr)
				ptr_a->target_nbr = ptr_b;
		}
		if (!ptr_a->target_nbr)
		{
			if (ptr_b->nbr < ptr_a->nbr)
				ptr_a->target_nbr = ptr_b;
		}
		ptr_b = ptr_b->next;
	}
	if (!ptr_a->target_nbr)
		find_target_max(data, ptr_a);
	return (0);
}

int	find_target_max(t_data *data, t_lst *ptr_a)
{
	t_lst	*ptr_b;

	ptr_b = data->b_col;
	while (ptr_b)
	{
		if (ptr_a->target_nbr)
		{
			if (ptr_b->nbr > ptr_a->target_nbr->nbr)
				ptr_a->target_nbr = ptr_b;
		}
		if (!ptr_a->target_nbr)
		{
			if (ptr_b->nbr > ptr_a->nbr)
				ptr_a->target_nbr = ptr_b;
		}
		ptr_b = ptr_b->next;
	}
	return (0);
}

int	find_target_2(t_data *data, t_lst *ptr_b)
{
	t_lst	*ptr_a;

	ptr_a = data->a_col;
	ptr_b->target_nbr = NULL;
	while (ptr_a)
	{
		if (ptr_b->target_nbr)
		{
			if (ptr_a->nbr > ptr_b->nbr && ptr_b->target_nbr->nbr > ptr_a->nbr)
				ptr_b->target_nbr = ptr_a;
		}
		if (!ptr_b->target_nbr)
		{
			if (ptr_a->nbr > ptr_b->nbr)
				ptr_b->target_nbr = ptr_a;
		}
		ptr_a = ptr_a->next;
	}
	if (!ptr_b->target_nbr)
		find_target_min(data, ptr_b);
	return (0);
}

int	find_target_min(t_data *data, t_lst *ptr_b)
{
	t_lst	*ptr_a;

	ptr_a = data->a_col;
	while (ptr_a)
	{
		if (ptr_b->target_nbr)
		{
			if (ptr_a->nbr < ptr_b->target_nbr->nbr)
				ptr_b->target_nbr = ptr_a;
		}
		if (!ptr_b->target_nbr)
		{
			if (ptr_a->nbr < ptr_b->nbr)
				ptr_b->target_nbr = ptr_a;
		}
		ptr_a = ptr_a->next;
	}
	return (0);
}
