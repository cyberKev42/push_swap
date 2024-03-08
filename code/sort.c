/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:50:48 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:32:24 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_data *data)
{
	int	size;

	size = ft_lstsize_utils(data->a_col);
	if (check_sorted(data))
		return (0);
	if (size == 2)
		sa(data, 0);
	else if (size == 3)
		sort_3(data);
	else
		sort_4plus(data);
	return (0);
}

int	sort_3(t_data *data)
{
	t_lst	*ptr;

	ptr = data->a_col;
	while (!(ptr->next->next->nbr > ptr->next->nbr
			&& ptr->next->next->nbr > ptr->nbr))
	{
		ra(data, 0);
		ptr = data->a_col;
	}
	if (check_sorted(data))
		return (0);
	sa(data, 0);
	return (0);
}

int	check_sorted(t_data *data)
{
	t_lst	*ptr;

	ptr = data->a_col;
	while (ptr->next)
	{
		if (ptr->nbr < ptr->next->nbr)
			ptr = ptr->next;
		else
			break ;
	}
	if (ptr->next)
		return (0);
	return (1);
}
