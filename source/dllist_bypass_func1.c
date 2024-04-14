/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:18:32 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/13 01:04:21 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_dllist_node	*up_next(t_bypass *bypass)
{
	return (bypass->cur->next);
}

t_dllist_node	*down_next(t_bypass *bypass)
{
	return (bypass->cur->prev);
}

int	eq_cond(t_bypass *bypass)
{
	return (bypass->cur->val == bypass->val);
}

int	gt_cond(t_bypass *bypass)
{
	return (bypass->cur->val > bypass->val);
}

int	gt_next_cond(t_bypass *bypass)
{
	return (bypass->cur->val > bypass->next(bypass)->val);
}
