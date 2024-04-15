/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:06:38 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/15 23:21:01 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	gt_ltd_cond(t_bypass *bypass)
{
	return (bypass->cur->val > bypass->const_val);
}

int	lt_cond(t_bypass *bypass)
{
	return (bypass->cur->val < bypass->val);
}

int	true_cond(t_bypass *bypass)
{
	(void)bypass;
	return (1);
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
