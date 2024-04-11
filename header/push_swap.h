/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:40 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 15:52:55 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define R_ 1
# define RR_ 2
# define S_ 4
# define OI_ 0
# include "common.h"
# include <limits.h>

typedef struct s_scheme
{
	int		a;
	int		b;
	size_t	moves_count;
}	t_scheme;

typedef struct s_sort_data
{
	int				from_perm;
	t_scheme		scheme;
	size_t			from_order;
	size_t			to_order;
	t_onode			to_prev_onode;
	t_dllist_node	*from_node;
	t_dllist_node	*from_node_tmp;
	size_t			from_order_tmp;
	size_t			to_order_tmp;
	t_scheme		scheme_tmp;
}	t_sort_data;

typedef struct s_dll_pivoted
{
	t_dllist		*l;
	t_dllist_node	*pivot;
	size_t			upper;
}	t_dll_pivoted;
#endif
