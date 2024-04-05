/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 20:27:45 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dllist	*a;
	t_dllist	*b;

	a = read_numbers(argv + 1, argc - 1);
	if (a)
	{
		b = create_dllist();
		if (b)
		{
			clear_dllist(b);
			free(b);
		}
		clear_dllist(a);
		free(a);
	}
}
