/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:39 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 16:57:03 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	rotate(t_dllist *l);

void	rra(t_dllist *a)
{
	if (rotate(a) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_dllist *b)
{
	if (rotate(b) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_dllist *a, t_dllist *b)
{
	int	tmp;

	tmp = rotate(a);
	if ((rotate(b) || tmp) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("rrr\n", 1);
}

static int	rotate(t_dllist *l)
{
	int	rotated;

	if (l->size > 1)
	{
		rotated = 1;
		l->top = l->top->next;
	}
	else
		rotated = 0;
	return (rotated);
}
