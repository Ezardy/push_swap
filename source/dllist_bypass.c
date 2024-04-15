/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:25:17 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/15 23:01:49 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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

int	not_end_cont_cond(t_bypass *bypass, t_dllist_node *cur_res)
{
	(void)cur_res;
	return (bypass->counter < bypass->depth);
}

int	matched_cont_cond(t_bypass *bypass, t_dllist_node *cur_res)
{
	return (not_end_cont_cond(bypass, NULL) && cur_res == NULL);
}

t_dllist_node	*dllist_bypass(t_dllist_node *node, t_bypass *bypass)
{
	t_dllist_node	*res;

	if (node)
	{
		res = bypass->init(node, bypass);
		bypass->counter = 0;
		while (bypass->cont_cond(bypass, res))
		{
			if (bypass->cond(bypass))
				res = bypass->action(bypass);
			bypass->cur = bypass->next(bypass);
			bypass->counter++;
		}
	}
	else
		res = NULL;
	return (res);
}
