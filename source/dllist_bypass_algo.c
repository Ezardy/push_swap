/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:10:56 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 22:50:58 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	dllist_find(t_dllist_node *start, size_t depth, int val, t_onode *res)
{
	t_bypass	bypass;

	bypass.val = val;
	bypass.init = first_match_init;
	bypass.cont_cond = matched_cont_cond;
	bypass.cond = eq_cond;
	bypass.next = down_next;
	bypass.depth = depth;
	dllist_bypass(start, &bypass, res);
}

void	dllist_max(t_dllist_node *start, size_t depth,
			t_dllist_node *(*next)(t_dllist_node *), t_onode *res)
{
	t_bypass	bypass;

	bypass.init = last_match_init;
	bypass.cont_cond = not_end_cont_cond;
	bypass.cond = gt_cond;
	bypass.next = next;
	bypass.depth = depth;
	dllist_bypass(start, &bypass, res);
}

void	dllist_min(t_dllist_node *start, size_t depth,
			t_dllist_node *(*next)(t_dllist_node *), t_onode *res)
{
	t_bypass	bypass;

	bypass.init = last_match_init;
	bypass.cont_cond = not_end_cont_cond;
	bypass.cond = lt_cond;
	bypass.next = next;
	bypass.depth = depth;
	dllist_bypass(start, &bypass, res);
}
