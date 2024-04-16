/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:18:32 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/16 14:14:05 by zanikin          ###   ########.fr       */
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

t_dllist_node	*null_init(t_dllist_node *node, t_bypass *bypass)
{
	bypass->cur = node;
	return (NULL);
}

t_dllist_node	*first_init(t_dllist_node *node, t_bypass *bypass)
{
	bypass->cur = node;
	bypass->val = node->val;
	bypass->cur = bypass->next(bypass);
	return (node);
}

int	true_cond(t_bypass *bypass)
{
	(void)bypass;
	return (1);
}
