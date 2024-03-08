/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:41:33 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/09 16:28:10 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_bonus/libft.h"
# include "printf/ft_printf.h"
# include <stdio.h>

typedef struct s_list_new
{
	int					nbr;
	int					index;
	int					first_half;
	int					cost;
	int					lowest_cost;
	struct s_list_new	*target_nbr;
	struct s_list_new	*next;
}				t_lst;

typedef struct s_data_struct
{
	t_lst	*a_col;
	t_lst	*b_col;
	char	**argv;
}				t_data;

int		pa(t_data *data);
int		pb(t_data *data);
int		sa(t_data *data, int n);
int		sb(t_data *data, int n);
int		ss(t_data *data);
int		ra(t_data *data, int n);
int		rb(t_data *data, int n);
int		rr(t_data *data);
int		rra(t_data *data, int n);
int		rrb(t_data *data, int n);
int		rrr(t_data *data);
int		sort(t_data *data);
int		sort_3(t_data *data);
int		check_sorted(t_data *data);
int		sort_4plus(t_data *data);
int		push_to_b(t_data *data);
int		push_to_a(t_data *data);
int		define_all_targets_for_a(t_data *data, t_lst *ptr1, t_lst *ptr2);
int		define_all_targets_for_b(t_data *data, t_lst *ptr1, t_lst *ptr2);
int		set_first_half(t_lst *ptr1, t_lst *ptr2);
int		set_index(t_lst *ptr1, t_lst *ptr2);
int		find_target(t_data *data, t_lst *ptr_a);
int		find_target_max(t_data *data, t_lst *ptr_a);
int		find_target_2(t_data *data, t_lst *ptr_b);
int		find_target_min(t_data *data, t_lst *ptr_b);
int		define_all_costs(t_lst *ptr1, t_lst *ptr2);
int		define_cost(t_lst *ptr1, t_lst *ptr2);
int		define_lowest_cost(t_lst *ptr1);
int		get_nodes_to_top(t_data *data, t_lst *ptr1, t_lst *ptr2);
int		rotate_up_down(t_data *data, t_lst *ptr, t_lst *ptr1, t_lst *ptr2);
int		rotate_ud_du(t_data *data, t_lst *ptr, t_lst *ptr1, t_lst *ptr2);
int		get_nodes_to_top_2(t_data *data, t_lst *ptr1, t_lst *ptr2);
int		rotate_up_down_2(t_data *data, t_lst *ptr, t_lst *ptr1, t_lst *ptr2);
int		rotate_ud_du_2(t_data *data, t_lst *ptr, t_lst *ptr1, t_lst *ptr2);
int		ft_lstadd_back_utils(t_lst **lst, t_lst *new);
int		ft_lstsize_utils(t_lst *lst);
int		check_intlast(int k, char nbr, int flag, char neg);
void	check_for_number(t_data *data, char **argv, int check);
void	check_for_int(t_data *data, char **argv, int check);
void	check_repeat(t_data *data);
void	ftsio(t_data *data);
void	sort_a(t_data *data, t_lst *ptr_a);
void	print_stacks(t_data *data);
t_lst	*ft_lstnew_utils(int content);

#endif