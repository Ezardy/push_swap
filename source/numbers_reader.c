/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:28:37 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/11 22:20:05 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static int	parse_strs(char **strs, t_dllist *l);
int			ft_atoi_safe(const char *str, int *num);

t_dllist	*read_numbers(char **params, int pcount)
{
	char		**nums;
	int			error;
	t_dllist	*dllist;

	dllist = create_dllist('a');
	if (dllist && pcount)
	{
		error = 0;
		while (!error && pcount--)
		{
			nums = ft_split(*params++, ' ');
			error = nums == 0 || parse_strs(nums, dllist);
		}
		if (error)
		{
			clear_dllist(dllist);
			free(dllist);
			dllist = NULL;
		}
		else
			dll_numerate(dllist);
	}
	return (dllist);
}

static int	parse_strs(char **strs, t_dllist *l)
{
	int		i;
	int		error;
	int		tmp;

	i = 0;
	error = 0;
	while (!error && strs[i])
	{
		error = ft_atoi_safe(strs[i++], &tmp);
		if (!error)
			error = dllist_find(l->top, l->size, tmp) != NULL
				|| dllist_push_back(l, tmp);
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs[i]);
	free(strs);
	return (error);
}
