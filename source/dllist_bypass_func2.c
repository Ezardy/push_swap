/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:06:38 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/16 14:14:16 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	gt_ltd_cond(t_bypass *bypass)
{
	return (bypass->cur->val > bypass->const_val && bypass->val
		> (bypass->cur->val - bypass->const_val));
}

int	lt_cond(t_bypass *bypass)
{
	return (bypass->cur->val < bypass->val);
}

int	eq_cond(t_bypass *bypass)
{
	return (bypass->cur->val == bypass->const_val);
}

int	gt_cond(t_bypass *bypass)
{
	return (bypass->cur->val > bypass->val);
}

int	gt_next_cond(t_bypass *bypass)
{
	return (bypass->cur->val > bypass->next(bypass)->val);
}
