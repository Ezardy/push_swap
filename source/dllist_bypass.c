/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:25:17 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 22:59:49 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_dllist_node	*first_match_init(t_dllist_node *node, t_bypass *bypass,
					t_onode *onode)
{
	(void *)bypass;
	onode->node = NULL;
	return (node);
}

t_dllist_node	*last_match_init(t_dllist_node *node, t_bypass *bypass,
					t_onode *onode)
{
	onode->node = node;
	onode->order = 0;
	return (bypass->next(node));
}

int	not_end_cont_cond(t_bypass *bypass, t_onode *onode)
{
	return (bypass->counter < bypass->depth);
}

int	matched_cont_cond(t_bypass *bypass, t_onode *onode)
{
	return (not_end_cont_cond(bypass, onode) && onode->node == NULL);
}

void	dllist_bypass(t_dllist_node *node, t_bypass *bypass, t_onode *onode)
{
	t_dllist_node	*cur;

	if (node)
	{
		cur = bypass->init(node, bypass, onode);
		bypass->counter = 0;
		while (bypass->cont_cond(bypass, onode))
		{
			if (bypass->cond(cur, bypass, onode))
			{
				onode->node = cur;
				onode->order = bypass->counter;
			}
			else
			{
				cur = bypass->next(cur);
				bypass->counter++;
			}
		}
	}
	else
		onode->node = NULL;
}
