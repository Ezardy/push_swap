/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:18:36 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/06 20:05:31 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	swap(t_dllist *a);

void	s_(t_dllist *l)
{
	if (swap(l) && PRINT_STACK_ACTIONS)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(l->id, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ss(t_dllist *a, t_dllist *b)
{
	int	tmp;

	tmp = swap(a);
	if ((swap(b) || tmp) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("ss\n", 1);
}

static int	swap(t_dllist *a)
{
	t_dllist_node	*prev;
	int				swaped;

	if (a->size > 1)
	{
		swaped = 1;
		prev = a->top->prev;
		prev->prev->next = a->top;
		a->top->prev = prev->prev;
		prev->prev = a->top;
		prev->next = a->top->next;
		a->top->next->prev = prev;
		a->top->next = prev;
		a->top = prev;
	}
	else
		swaped = 0;
	return (swaped);
}
