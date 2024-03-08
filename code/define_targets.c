/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_targets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:58:19 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_all_targets_for_a(t_data *data, t_lst *ptr1, t_lst *ptr2)
{
	set_index(ptr1, ptr2);
	set_first_half(ptr1, ptr2);
	while (ptr1)
	{
		find_target(data, ptr1);
		ptr1 = ptr1->next;
	}
	return (0);
}

int	define_all_targets_for_b(t_data *data, t_lst *ptr1, t_lst *ptr2)
{
	set_index(ptr1, ptr2);
	set_first_half(ptr1, ptr2);
	while (ptr1)
	{
		find_target_2(data, ptr1);
		ptr1 = ptr1->next;
	}
	return (0);
}

int	set_first_half(t_lst *ptr1, t_lst *ptr2)
{
	t_lst	*ptr;
	int		highest_index;
	int		i;

	ptr = ptr1;
	while (ptr->next)
		ptr = ptr->next;
	highest_index = ptr->index;
	ptr = ptr1;
	i = 2;
	while (i--)
	{
		while (ptr)
		{
			if (ptr->index <= (highest_index / 2))
				ptr->first_half = 1;
			else
				ptr->first_half = 0;
			ptr = ptr->next;
		}
		ptr = ptr2;
	}
	return (0);
}

int	set_index(t_lst *ptr_a, t_lst *ptr_b)
{
	t_lst	*ptr1;
	t_lst	*ptr2;
	int		i;

	ptr1 = ptr_a;
	ptr2 = ptr_b;
	i = 0;
	while (ptr1)
	{
		ptr1->index = i;
		ptr1 = ptr1->next;
		i++;
	}
	i = 0;
	while (ptr2)
	{
		ptr2->index = i;
		ptr2 = ptr2->next;
		i++;
	}
	return (0);
}
