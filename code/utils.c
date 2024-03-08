/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:32:46 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew_utils(int content)
{
	t_lst	*start;

	start = (t_lst *) malloc (sizeof(t_lst));
	if (!start)
		return (NULL);
	start->nbr = content;
	start->next = NULL;
	return (start);
}

int	ft_lstadd_back_utils(t_lst **lst, t_lst *new)
{
	t_lst	*ptr;

	if (!new)
		return (1);
	ptr = *lst;
	if (*lst)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		ptr = NULL;
	}
	else
		*lst = new;
	return (0);
}

int	ft_lstsize_utils(t_lst *lst)
{
	int		count;
	t_lst	*ptr;

	count = 0;
	if (!lst)
		return (0);
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

void	check_for_int(t_data *data, char **argv, int check)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	flag = 0;
	if (check)
		i++;
	while (argv[i])
	{
		k = -1;
		while (argv[i][++k])
		{
			if (k == 0 && (argv[i][k] == '-' || argv[i][k] == '+'))
				flag = 1;
			if (k > 9 + flag || check_intlast(k, argv[i][k], flag, argv[i][0]))
			{
				ft_printf("Error\nI can only sort integers ;)\n");
				ftsio(data);
			}
		}
		i++;
	}
}

void	check_repeat(t_data *data)
{
	t_lst	*ptr;
	t_lst	*ptr1;

	ptr = data->a_col;
	ptr1 = data->a_col;
	ptr = ptr->next;
	while (ptr1)
	{
		while (ptr)
		{
			if (ptr->nbr == ptr1->nbr)
			{
				ft_printf("Error\nDont't use duplicate numbers!\n");
				ftsio(data);
			}
			ptr = ptr->next;
		}
		ptr1 = ptr1->next;
		if (ptr1)
			ptr = ptr1->next;
	}
}
