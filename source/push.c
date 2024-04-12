/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:01:08 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/11 22:24:13 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int		push(t_dllist *a, t_dllist *b);
t_dllist_node	*pop(t_dllist *a);

void	p_(t_dllist *to, t_dllist *from)
{
	if (push(from, to))
	{
		dll_numerate(to);
		dll_numerate(from);
		if (PRINT_STACK_ACTIONS)
		{
			ft_putchar_fd('p', 1);
			ft_putchar_fd(to->id, 1);
			ft_putchar_fd('\n', 1);
		}
	}
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
