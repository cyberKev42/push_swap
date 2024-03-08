/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_costs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:40:55 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_all_costs(t_lst *ptr1, t_lst *ptr2)
{
	define_cost(ptr1, ptr2);
	define_lowest_cost(ptr1);
	return (0);
}

int	define_cost(t_lst *ptr1, t_lst *ptr2)
{
	t_lst	*ptr;
	int		cost;
	int		stack_a_size;
	int		stack_b_size;

	stack_a_size = ft_lstsize_utils(ptr1);
	stack_b_size = ft_lstsize_utils(ptr2);
	ptr = ptr1;
	while (ptr)
	{
		cost = ptr->index;
		if (!ptr->first_half)
			cost = stack_a_size - ptr->index;
		if (ptr->target_nbr->first_half)
			cost += ptr->target_nbr->index;
		else
			cost += stack_b_size - ptr->target_nbr->index;
		ptr->cost = cost;
		ptr = ptr->next;
	}
	return (0);
}

int	define_lowest_cost(t_lst *ptr1)
{
	t_lst	*ptr;
	int		i;
	int		lowest;

	ptr = ptr1;
	lowest = 2147483647;
	while (ptr)
	{
		ptr->lowest_cost = 0;
		if (ptr->cost < lowest)
		{
			i = ptr->index;
			lowest = ptr->cost;
		}
		ptr = ptr->next;
	}
	ptr = ptr1;
	while (ptr)
	{
		if (ptr->index == i)
			ptr->lowest_cost = 1;
		ptr = ptr->next;
	}
	return (0);
}
