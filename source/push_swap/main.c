/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 21:17:17 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_dllist *a, t_dllist *b);

int	main(int argc, char **argv)
{
	t_dllist	*a;
	t_dllist	*b;
	int			error;

	error = 1;
	a = read_numbers(argv + 1, argc - 1);
	if (a)
	{
		b = create_dllist();
		if (b)
		{
			if (!dll_is_sorted(a))
				sort(a, b);
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
	if (a->size < 3)
	{
		if (a->top->val > a->top->prev->val)
			sa(a);
	}
	else
	{
		while (a->size > 5)
		{

		}
		pb(a, b);
		pb(a, b);
	}
}
