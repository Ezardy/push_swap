/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:04:40 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/16 14:14:45 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_dllist_node	*diff_action(t_bypass *bypass)
{
	bypass->val = bypass->cur->val - bypass->const_val;
	return (bypass->cur);
}

t_dllist_node	*count_action(t_bypass *bypass)
{
	bypass->cur->order = bypass->counter;
	return (NULL);
}

t_dllist_node	*assign_action(t_bypass *bypass)
{
	bypass->val = bypass->cur->val;
	return (bypass->cur);
}

int	not_end_cont_cond(t_bypass *bypass, t_dllist_node *cur_res)
{
	(void)cur_res;
	return (bypass->counter < bypass->depth);
}

int	matched_cont_cond(t_bypass *bypass, t_dllist_node *cur_res)
{
	return (not_end_cont_cond(bypass, NULL) && cur_res == NULL);
}
