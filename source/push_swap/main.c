/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/11 00:11:55 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_dllist *a, t_dllist *b);
static void	a2b(t_dllist *a, t_dll_pivoted *b);

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
			if (a->size > 3)
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
	t_onode			onode;
	t_dll_pivoted	dllp;

	while (a->size > 5 && b->size < 3)
		p_(b, a);
	dllist_min(b->top, b->size, down_next, &onode);
	dllp.pivot = onode.node;
	dllp.l = b;
	dllp.upper = b->size > 1;
	while (a->size > 5)
		a2b(a, &dllp);
	while (a->size > 3)
		p_(b, a);
	dllist_max(a->top, a->size, down_next, &onode);
	if (onode.order == 0)
		r_(a);
	else if (onode.order == 1)
		rr_(a);
	if (a->top->val > a->top->prev->val)
		s_(a);
	// b2a_simple x2
	// b2a
}

static void	a2b(t_dllist *a, t_dll_pivoted *b)
{

}
