/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:29:32 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/15 17:02:18 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_funcs(t_scheme *scheme, void (**rota)(t_dllist *),
				void (**rotb)(t_dllist *), void (**prot)(t_dllist *,
					t_dllist *));
static void	set_scheme(t_scheme *scm, size_t f, size_t t, int s);

void	select_upper_scheme(t_dllist *a, t_dll_pivoted *b, t_scheme *scheme)
{
	scheme->is_upper = 1;
	scheme->to_node = dllist_bigger(b->pivot, abs_diff(b->pivot->order,
				b->upper->order) + 1, scheme->from_node->val, up_next);
	if (!scheme->to_node)
		scheme->to_node = b->upper;
	else
		scheme->to_node = scheme->to_node->prev;
	select_scheme(scheme, a->size, b->l->size, scheme->from_node->order);
}

void	select_scheme(t_scheme *sdata, size_t f_s, size_t t_s, size_t f_o)
{
	t_scheme	tmp;

	sdata->from_scheme = R_;
	sdata->to_scheme = R_;
	set_scheme(sdata, f_o, sdata->to_node->order, 1);
	tmp = *sdata;
	tmp.to_scheme = RR_;
	set_scheme(&tmp, f_o, t_s - sdata->to_node->order, 0);
	if (tmp.moves_count < sdata->moves_count)
		*sdata = tmp;
	tmp.from_scheme = RR_;
	set_scheme(&tmp, f_s - f_o, t_s - sdata->to_node->order, 1);
	if (tmp.moves_count < sdata->moves_count)
		*sdata = tmp;
	tmp.to_scheme = R_;
	set_scheme(&tmp, f_s - f_o, sdata->to_node->order, 0);
	if (tmp.moves_count < sdata->moves_count)
		*sdata = tmp;
}

static void	set_scheme(t_scheme *scm, size_t f, size_t t, int s)
{
	if (s)
	{
		scm->moves_count = ft_min(f, t);
		scm->from_count = f - scm->moves_count;
		scm->to_count = t - scm->moves_count;
		scm->moves_count += scm->from_count + scm->to_count;
	}
	else
	{
		scm->moves_count = f + t;
		scm->from_count = f;
		scm->to_count = t;
	}
}

void	execute_scheme(t_dllist *a, t_dll_pivoted *b, t_scheme *scheme)
{
	void	(*rota)(t_dllist *);
	void	(*rotb)(t_dllist *);
	void	(*prot)(t_dllist *, t_dllist *);
	size_t	acts;

	set_funcs(scheme, &rota, &rotb, &prot);
	acts = scheme->moves_count - scheme->from_count - scheme->to_count;
	while (acts--)
		prot(a, b->l);
	acts = scheme->from_count;
	while (acts--)
		rota(a);
	acts = scheme->to_count;
	while (acts--)
		rotb(b->l);
	p_(b->l, a);
	if (scheme->from_node->val < b->pivot->val)
		b->pivot = scheme->from_node;
	else if (scheme->is_upper && scheme->from_node->val > b->upper->val)
		b->upper = scheme->from_node;
	else if (!scheme->is_upper && scheme->from_node->val > b->lower->val)
		b->lower = scheme->from_node;
}

static void	set_funcs(t_scheme *scheme, void (**rota)(t_dllist *),
				void (**rotb)(t_dllist *), void (**prot)(t_dllist *,
				t_dllist *))
{
	if (scheme->from_scheme == R_)
		*rota = r_;
	else
		*rota = rr_;
	if (scheme->to_scheme == R_)
		*rotb = r_;
	else
		*rotb = rr_;
	if (scheme->from_scheme == scheme->to_scheme)
	{
		if (scheme->from_scheme == R_)
			*prot = rr;
		else
			*prot = rrr;
	}
	else
		*prot = NULL;
}
