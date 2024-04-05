/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:59:18 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 16:23:13 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	rotate_down(t_dllist *l);

void	ra(t_dllist *a)
{
	if (rotate_down(a) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_dllist *b)
{
	if (rotate_down(b) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_dllist *a, t_dllist *b)
{
	int	tmp;

	tmp = rotate_down(a);
	if ((rotate_down(b) || tmp) && PRINT_STACK_ACTIONS)
		ft_putstr_fd("rr\n", 1);
}

static int	rotate_down(t_dllist *l)
{
	int	rotated;

	if (l->size > 1)
	{
		rotated = 1;
		l->top = l->top->prev;
	}
	else
		rotated = 0;
	return (rotated);
}
