/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:53:13 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/15 14:21:54 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_c(t_dllist *l, void (*func)(t_dllist *), size_t count)
{
	while (count--)
		func(l);
}

void	func2_c(t_dllist *a, t_dllist *b, void (*func2)(t_dllist *, t_dllist *),
			size_t count)
{
	while (count--)
		func2(a, b);
}

void	rot_to_bottom(t_dllist *l, t_dllist_node *node)
{
	size_t	up;
	size_t	down;

	if (node)
	{
		dll_numerate(l);
		up = node->order + 1;
		down = l->size - node->order - 1;
		if (up < down)
			func_c(l, r_, up);
		else
			func_c(l, rr_, down);
	}
}

void	rot_to_top(t_dllist *l, t_dllist_node *node)
{
	size_t	up;
	size_t	down;

	if (node)
	{
		dll_numerate(l);
		up = node->order;
		down = l->size - node->order;
		if (up < down)
			func_c(l, r_, up);
		else
			func_c(l, rr_, down);
	}
}

void	pop_to(t_dllist *from, t_dllist *to)
{
	t_dllist_node	*bigger;

	if (from->size)
	{
		bigger = dllist_bigger(to->top, to->size, from->top->val, down_next);
		if (bigger)
			rot_to_bottom(to, bigger);
		p_(to, from);
	}
}
