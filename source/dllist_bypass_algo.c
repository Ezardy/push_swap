/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:10:56 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/15 13:46:19 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_dllist_node	*dllist_find(t_dllist_node *start, size_t depth, int val)
{
	t_bypass	bypass;

	bypass.val = val;
	bypass.init = first_match_init;
	bypass.cont_cond = matched_cont_cond;
	bypass.cond = eq_cond;
	bypass.action = assign_action;
	bypass.next = down_next;
	bypass.depth = depth;
	return (dllist_bypass(start, &bypass));
}

t_dllist_node	*dllist_bigger(t_dllist_node *start, size_t depth, int val,
			t_dllist_node *(*next)(t_bypass *))
{
	t_bypass	bypass;

	bypass.val = val;
	bypass.init = first_match_init;
	bypass.cont_cond = matched_cont_cond;
	bypass.cond = gt_cond;
	bypass.action = assign_action;
	bypass.next = next;
	bypass.depth = depth;
	return (dllist_bypass(start, &bypass));
}

t_dllist_node	*dllist_max(t_dllist_node *start, size_t depth,
			t_dllist_node *(*next)(t_bypass *))
{
	t_bypass	bypass;

	bypass.init = last_match_init;
	bypass.cont_cond = not_end_cont_cond;
	bypass.cond = gt_cond;
	bypass.action = assign_action;
	bypass.next = next;
	bypass.depth = depth - 1;
	return (dllist_bypass(start, &bypass));
}

t_dllist_node	*dllist_min(t_dllist_node *start, size_t depth,
			t_dllist_node *(*next)(t_bypass *))
{
	t_bypass	bypass;

	bypass.init = last_match_init;
	bypass.cont_cond = not_end_cont_cond;
	bypass.cond = lt_cond;
	bypass.action = assign_action;
	bypass.next = next;
	bypass.depth = depth - 1;
	return (dllist_bypass(start, &bypass));
}
