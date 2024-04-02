/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/02 14:16:03 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	*array;
	int	i;
	int	num_count;

	num_count = read_numbers(argv + 1, argc - 1, &array);
	if (num_count == -1)
		ft_putstr_fd("Error", 1);
	else
	{
		if (num_count)
			ft_putnbr_fd(array[0], 1);
		i = 1;
		while (i < num_count)
		{
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(array[i++], 1);
		}
	}
	ft_putchar_fd('\n', 1);
	free(array);
}
