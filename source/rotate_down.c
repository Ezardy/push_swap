/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:39 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/06 20:04:52 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	rotate(t_dllist *l);

void	rr_(t_dllist *l)
{
	if (rotate(l) && PRINT_STACK_ACTIONS)
	{
		ft_putstr_fd("ss", 1);
		ft_putchar_fd(l->id, 1);
		ft_putchar_fd('\n', 1);
	}
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
