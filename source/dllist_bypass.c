/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_bypass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:25:17 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 21:13:12 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_dllist_node	*dllist_last(t_dllist *l, int (*cond)(t_dllist_node *,
						t_dllist_node *));

t_dllist_node	*dllist_find(t_dllist *l, int (*cond)(int, int), int val)
{
	size_t			i;
	t_dllist_node	*node;
	t_dllist_node	*found;

	i = 0;
	found = NULL;
	node = l->top;
	while (i++ < l->size && !found)
	{
		if (cond(node->val, val))
			found = node;
		else
			node = node->prev;
	}
	return (found);
}

void	dllist_iter(t_dllist *l, void (*fun)(int))
{
	size_t			i;
	t_dllist_node	*node;

	i = 0;
	node = l->top;
	while (i++ < l->size)
	{
		fun(node->val);
		node = node->prev;
	}
}
