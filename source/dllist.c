/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:11:39 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/17 21:24:08 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

int	dllist_push_back(t_dllist *l, int val)
{
	int				error;
	t_dllist_node	*node;

	error = 1;
	node = (t_dllist_node *)malloc(sizeof(t_dllist_node));
	if (node)
	{
		node->val = val;
		if (l->top)
		{
			l->top->next->prev = node;
			node->next = l->top->next;
			node->prev = l->top;
			l->top->next = node;
		}
		else
		{
			node->next = node;
			node->prev = node;
			l->top = node;
		}
		l->size++;
		error = 0;
	}
	return (error);
}

void	clear_dllist(t_dllist *l)
{
	t_dllist_node	*cur_node;
	t_dllist_node	*next_node;

	if (l && l->top)
	{
		cur_node = l->top->next;
		while (cur_node != l->top)
		{
			next_node = cur_node->next;
			free(cur_node);
			cur_node = next_node;
		}
		free(l->top);
		l->top = NULL;
		l->size = 0;
	}
}

t_dllist	*create_dllist(char id)
{
	t_dllist	*l;

	l = (t_dllist *)malloc(sizeof(t_dllist));
	if (l)
	{
		l->id = id;
		l->size = 0;
		l->top = NULL;
		l->ordered = 0;
	}
	return (l);
}

int	dll_is_sorted(t_dllist *l)
{
	t_bypass	bypass;

	bypass.depth = l->size - 1;
	bypass.init = null_init;
	bypass.cont_cond = matched_cont_cond;
	bypass.cond = gt_next_cond;
	bypass.action = assign_action;
	bypass.next = down_next;
	return (dllist_bypass(l->top, &bypass) == NULL);
}

void	dll_numerate(t_dllist *l)
{
	t_bypass	bypass;

	if (!l->ordered)
	{
		bypass.depth = l->size;
		bypass.init = null_init;
		bypass.cont_cond = not_end_cont_cond;
		bypass.cond = true_cond;
		bypass.action = count_action;
		bypass.next = down_next;
		dllist_bypass(l->top, &bypass);
		l->ordered = 1;
	}
}
