/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:18:32 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 17:29:16 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_dllist_node	*up_next(t_dllist_node *node)
{
	return (node->next);
}

t_dllist_node	*down_next(t_dllist_node *node)
{
	return (node->prev);
}

int	val_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode)
{
	(void *)onode;
	return (node->val == bypass->val);
}

int	gt_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode)
{
	(void *)bypass;
	return (node->val > onode->node->val);
}

int	gt_next_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode)
{
	(void *)onode;
	return (node->val > bypass->next(node)->val);
}
