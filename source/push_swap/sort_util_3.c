/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:56:29 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/14 18:38:09 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	abs_diff(size_t a, size_t b)
{
	size_t	diff;

	if (a > b)
		diff = a - b;
	else
		diff = b - a;
	return (diff);
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
