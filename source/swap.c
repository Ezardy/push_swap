/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:18:36 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/03 17:54:17 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	swap(t_dllist *a);

void	sa(t_dllist *a)
{
	if (swap(a) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_dllist *b)
{
	if (swap(b) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("sb\n", 1);
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
