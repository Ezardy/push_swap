/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/17 20:56:35 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	sort(t_dllist *a, t_dllist *b);
static void	a2b(t_dllist *a, t_dll_pivoted *b);
static int	b2a(t_dllist *a, t_dll_pivoted *b);
static void	align(t_dllist *a, t_dll_pivoted *b);

int	main(int argc, char **argv)
{
	t_dllist	*a;
	t_dllist	*b;
	int			error;

	error = 1;
	a = read_numbers(argv + 1, argc - 1);
	if (a)
	{
		b = create_dllist('b');
		if (b)
		{
			if (a->size > 2)
				sort(a, b);
			else if (a->top->val > a->top->prev->val)
				s_(a);
			error = 0;
			clear_dllist(b);
			free(b);
		}
		clear_dllist(a);
		free(a);
	}
	if (error)
		ft_putstr_fd("Error\n", 1);
	return (error);
}

static void	sort(t_dllist *a, t_dllist *b)
{
	t_dll_pivoted	dllp;

	func2_c(b, a, p_, ft_min(3, (a->size > 5) * (a->size - 5)));
	dllp.pivot = dllist_min(b->top, b->size, down_next);
	dllp.l = b;
	if (dllp.pivot && b->size > 1)
		dllp.upper = dllp.pivot->next;
	else
		dllp.upper = NULL;
	if (dllp.pivot && b->size > 2)
		dllp.lower = dllp.pivot->prev;
	else
		dllp.lower = NULL;
	while (a->size > 5)
		a2b(a, &dllp);
	func2_c(b, a, p_, a->size - 3);
	rot_to_bottom(a, dllist_max(a->top, a->size, down_next));
	if (a->top->val > a->top->prev->val)
		s_(a);
	pop_to(b, a);
	pop_to(b, a);
	rot_to_bottom(a, dllist_max(a->top, a->size, down_next));
	b2a(a, &dllp);
	align(a, &dllp);
}

static void	a2b(t_dllist *a, t_dll_pivoted *b)
{
	t_scheme		scheme_tmp;
	t_scheme		scheme;
	size_t			from_order;

	from_order = 0;
	scheme_tmp.from_node = a->top;
	scheme.moves_count = ULONG_MAX;
	dll_numerate(a);
	dll_numerate(b->l);
	while (from_order < a->size)
	{
		select_upper_scheme(a, b, &scheme_tmp);
		if (scheme_tmp.moves_count < scheme.moves_count)
			scheme = scheme_tmp;
		scheme_tmp.is_upper = 0;
		scheme_tmp.to_node = dllist_bigger(b->pivot, dist(b, 0),
				scheme_tmp.from_node->val, down_next);
		if (!scheme_tmp.to_node)
			scheme_tmp.to_node = b->lower->prev;
		select_scheme(&scheme_tmp, a->size, b->l->size, from_order++);
		if (scheme_tmp.moves_count < scheme.moves_count)
			scheme = scheme_tmp;
		scheme_tmp.from_node = scheme_tmp.from_node->prev;
	}
	execute_scheme(a, b, &scheme);
}

static int	b2a(t_dllist *a, t_dll_pivoted *b)
{
	size_t	stock;

	if (b->l->size)
		stock = a->size;
	else
		stock = 0;
	rot_to_top(b->l, b->upper);
	while (b->lower || b->upper || stock)
	{
		if (pick_upper_or_lower(a, b, stock))
			p_(a, b->l);
		else if (stock && (!b->pivot || b->upper || b->lower
				|| a->top->next->val > b->pivot->val))
		{
			stock--;
			rr_(a);
		}
		else
		{
			p_(a, b->l);
			b->pivot = NULL;
		}
	}
	return (stock);
}

static void	align(t_dllist *a, t_dll_pivoted *b)
{
	p_(a, b->l);
	rot_to_top(a, dllist_min(a->top, a->size, down_next));
}
