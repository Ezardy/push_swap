/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:25:17 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/16 14:14:38 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
