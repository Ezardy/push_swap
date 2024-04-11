/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:06:38 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 21:21:29 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	eq_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode)
{
	(void *)onode;
	return (node->val == bypass->val);
}

int	lt_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode)
{
	(void *)bypass;
	return (node->val < onode->node->val);
}