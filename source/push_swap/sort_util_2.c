/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:53:13 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/13 16:45:13 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_bottom(t_dllist *l, t_dllist_node *node)
{
	void			(*rot)(t_dllist *);

	if (node->order + 1 < l->size - node->order - 1)
		rot = r_;
	else
		rot = rr_;
	while (node->order < l->size - 1)
		rot(l);
}

void	pop_to(t_dllist *from, t_dllist *to)
{
	t_dllist_node	*bigger;

	bigger = dllist_bigger(to->top, to->size, from->top->val, down_next);
	if (bigger)
		rot_to_bottom(to, bigger);
	p_(to, from);
}

size_t	abs_diff(size_t a, size_t b)
{
	size_t	diff;

	if (a > b)
		diff = a - b;
	else
		diff = b - a;
	return (diff);
}

size_t	ft_max(size_t a, size_t b)
{
	size_t	max;

	if (a > b)
		max = a;
	else
		max = b;
	return (max);
}

size_t	ft_min(size_t a, size_t b)
{
	size_t	min;

	if (a > b)
		min = b;
	else
		min = a;
	return (min);
}
