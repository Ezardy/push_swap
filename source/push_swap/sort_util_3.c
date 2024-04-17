/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:56:29 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/17 16:43:52 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	dist(t_dll_pivoted *pl, int u)
{
	size_t	d;

	if (u)
	{
		if (pl->upper->order > pl->pivot->order)
			d = pl->l->size - pl->upper->order + pl->pivot->order + 1;
		else
			d = pl->pivot->order - pl->upper->order + 1;
	}
	else
	{
		if (pl->pivot->order > pl->lower->order)
			d = pl->l->size - pl->pivot->order + pl->lower->order + 1;
		else
			d = pl->lower->order - pl->pivot->order + 1;
	}
	return (d);
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

int	pick_upper_or_lower(t_dllist *a, t_dll_pivoted *b, size_t stock)
{
	int	picked;

	if (b->upper && (!b->lower || b->upper->val > b->lower->val)
		&& (!stock || b->upper->val > a->top->next->val))
	{
		b->upper = b->upper->prev;
		if (b->upper->val == b->pivot->val)
			b->upper = NULL;
		picked = 1;
	}
	else if (b->lower && (!stock || b->lower->val > a->top->next->val))
	{
		b->lower = b->lower->next;
		if (b->lower->val == b->pivot->val)
			b->lower = NULL;
		rr_(b->l);
		picked = 1;
	}
	else
		picked = 0;
	return (picked);
}