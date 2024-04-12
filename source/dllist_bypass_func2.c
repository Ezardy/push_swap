/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:06:38 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/11 21:56:42 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	lt_cond(t_bypass *bypass, t_dllist_node *cur_res)
{
	return (bypass->cur->val < cur_res->val);
}

int	true_cond(t_bypass *bypass, t_dllist_node *cur_res)
{
	(void *)bypass;
	(void *)cur_res;
	return (1);
}

t_dllist_node	*count_action(t_bypass *bypass)
{
	bypass->cur->order = bypass->counter;
	return (NULL);
}

t_dllist_node	*assign_action(t_bypass *bypass)
{
	return (bypass->cur);
}
