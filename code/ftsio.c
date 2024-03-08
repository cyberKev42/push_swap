/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:15:04 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:32:35 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ftsio(t_data *data)
{
	t_lst	*ptr;
	int		i;

	ptr = data->a_col;
	while (data->a_col)
	{
		ptr = ptr->next;
		free(data->a_col);
		data->a_col = ptr;
	}
	ptr = data->b_col;
	while (data->b_col)
	{
		ptr = ptr->next;
		free(data->b_col);
		data->b_col = ptr;
	}
	i = 0;
	if (data->argv)
	{
		while (data->argv[i])
			free(data->argv[i++]);
		free(data->argv);
	}
	exit (0);
}

int	check_intlast(int k, char nbr, int flag, char neg)
{
	if (flag == 0)
	{
		if (k == 9 && (nbr == '8' || nbr == '9'))
			return (1);
		if (k == 10 && nbr == '9')
			return (1);
	}
	else
	{
		if (neg == '+')
		{
			if (k == 10 && (nbr == '8' || nbr == '9'))
				return (1);
		}
		if (k == 10 && nbr == '9')
			return (1);
	}
	return (0);
}
