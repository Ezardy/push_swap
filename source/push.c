/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:01:08 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 18:55:54 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int		push(t_dllist *a, t_dllist *b);
t_dllist_node	*pop(t_dllist *a);

void	pa(t_dllist *a, t_dllist *b)
{
	if (push(b, a) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_dllist *a, t_dllist *b)
{
	if (push(a, b) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("pb\n", 1);
}

static int	push(t_dllist *a, t_dllist *b)
{
	int				pushed;
	t_dllist_node	*node;

	if (a->size)
	{
		pushed = 1;
		node = pop(a);
		if (b->size++)
		{
			node->next = b->top->next;
			node->prev = b->top;
			b->top->next->prev = node;
			b->top->next = node;
		}
		else
		{
			node->next = node;
			node->prev = node;
		}
		b->top = node;
	}
	else
		pushed = 0;
	return (pushed);
}

t_dllist_node	*pop(t_dllist *a)
{
	t_dllist_node	*node;

	node = a->top;
	if (--(a->size))
	{
		a->top = node->prev;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else
		a->top = NULL;
	return (node);
}
