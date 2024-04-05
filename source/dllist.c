/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:11:39 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 21:08:46 by zanikin          ###   ########.fr       */
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

	if (l->top)
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

t_dllist	*create_dllist(void)
{
	t_dllist	*l;

	l = (t_dllist *)malloc(sizeof(t_dllist));
	if (l)
	{
		l->size = 0;
		l->top = NULL;
	}
	return (l);
}

int	dll_is_sorted(t_dllist *l)
{
	t_dllist_node	*cur;
	size_t			i;
	int				sorted;

	sorted = 1;
	if (l->size > 1)
	{
		i = 1;
		cur = l->top;
		while (sorted && i++ < l->size)
			sorted = cur->val < cur->prev->val;
	}
	return (sorted);
}
