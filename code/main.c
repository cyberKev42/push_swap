/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:40:16 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:36 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_number(t_data *data, char **argv, int check)
{
	int	i;
	int	k;

	i = 0;
	if (check)
		i++;
	while (argv[i])
	{
		k = -1;
		while (argv[i][++k])
		{
			if (k == 0 && (argv[i][k] == '-' || argv[i][k] == '+'))
				continue ;
			if (argv[i][k] < '0' || argv[i][k] > '9')
			{
				ft_printf("Error\nI can only sort numbers ;)\n");
				ftsio(data);
			}
		}
		i++;
	}
}

void	print_stacks(t_data *data)
{
	t_lst	*ptra;
	t_lst	*ptrb;

	ptra = data->a_col;
	ptrb = data->b_col;
	while (ptra || ptrb)
	{
		if (ptra && ptrb)
			ft_printf(" %d    %d\n", ptra->nbr, ptrb->nbr);
		else if (ptra)
			ft_printf(" %d\n", ptra->nbr);
		else
			ft_printf("      %d\n", ptrb->nbr);
		if (ptra)
			ptra = ptra->next;
		if (ptrb)
			ptrb = ptrb->next;
	}
	ft_printf(" _    _\n");
	ft_printf(" a    b\n\n");
}

static void	init_main(t_data *data)
{
	data->a_col = NULL;
	data->b_col = NULL;
	data->argv = NULL;
}

void	create_lst(int c, char **argv, t_data *data, int check)
{
	int		i;
	int		nbr;

	if (check == 0)
		c--;
	check_for_number(data, argv, check);
	check_for_int(data, argv, check);
	i = 1 + check;
	nbr = ft_atoi(argv[check]);
	data->a_col = ft_lstnew_utils(nbr);
	if (!data->a_col)
		ftsio(data);
	while (i < c || argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (ft_lstadd_back_utils(&data->a_col, ft_lstnew_utils(nbr)))
			ftsio(data);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_main(&data);
	if (argc == 1)
		return (printf("Error\nNo arguments!"), 0);
	if (argc == 2)
	{
		data.argv = ft_split(argv[1], ' ');
		if (!data.argv)
			exit (0);
		create_lst(argc, data.argv, &data, 0);
	}
	else
		create_lst(argc, argv, &data, 1);
	check_repeat(&data);
	sort(&data);
	ftsio(&data);
	return (0);
}
