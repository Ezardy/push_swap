/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:54:39 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/11 22:34:01 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	rotate(t_dllist *l);

void	rr_(t_dllist *l)
{
	if (rotate(l))
	{
		dll_numerate(l);
		if (PRINT_STACK_ACTIONS)
		{
			ft_putstr_fd("rr", 1);
			ft_putchar_fd(l->id, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	rrr(t_dllist *a, t_dllist *b)
{
	int	ar;
	int	br;

	ar = rotate(a);
	if (ar)
		dll_numerate(a);
	br = rotate(b);
	if (br)
		dll_numerate(b);
	if ((br || ar) && PRINT_STACK_ACTIONS)
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
