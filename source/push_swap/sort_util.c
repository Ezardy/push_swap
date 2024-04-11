/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:29:32 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 13:50:41 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max(int a, int b);
static void	select_scheme(t_sort_data *sdata, size_t f_size, size_t t_size);
static void	set_scheme(t_sort_data *sdata, int f_scm, int i_scm, size_t count);

void	a_to_b_common(t_dllist *a, t_dllist *b)
{
	t_sort_data		sdata;

	sdata.from_node_tmp = a->top;
	sdata.from_order_tmp = 0;
	sdata.scheme.moves_count = ULONG_MAX;
	while (sdata.from_order_tmp < a->size)
	{
		dllist_find(b, dll_gt, sdata.from_node_tmp->val, &sdata.to_prev_onode);
		select_scheme(&sdata, a->size, b->size);
		if (sdata.scheme_tmp.moves_count < sdata.scheme.moves_count)
		{
			sdata.scheme.a = sdata.scheme_tmp.a;
			sdata.scheme.b = sdata.scheme_tmp.b;
			sdata.scheme.moves_count = sdata.scheme_tmp.moves_count;
		}
	}
}

static void	select_scheme(t_sort_data *sdata, size_t f_size, size_t t_size)
{
	sdata->scheme_tmp.a = R_;
	sdata->scheme_tmp.b = R_;
	sdata->scheme_tmp.moves_count = ft_max(sdata->from_order_tmp,
			sdata->to_prev_onode.order) + 1;
	set_scheme(sdata, R_, RR_, sdata->from_order_tmp + 1 + t_size
		- sdata->to_prev_onode.order);
	set_scheme(sdata, RR_, RR_, ft_max(f_size - sdata->from_order_tmp, t_size
			- sdata->to_prev_onode.order) + 1);
	set_scheme(sdata, RR_, R_, f_size - sdata->from_order_tmp + 1
		+ sdata->to_prev_onode.order);
}

static void	set_scheme(t_sort_data *sdata, int f_scm, int i_scm, size_t count)
{
	if (count < sdata->scheme_tmp.moves_count)
	{
		sdata->scheme_tmp.a = f_scm;
		sdata->scheme_tmp.b = i_scm;
		sdata->scheme_tmp.moves_count = count;
	}
}

static int	ft_max(int a, int b)
{
	int	max;

	if (a > b)
		max = a;
	else
		max = b;
	return (max);
}
