/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:28:37 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 21:12:46 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static int	node_matches(int val, int oval);
static int	parse_strs(char **strs, t_dllist *l);
int			ft_atoi_safe(const char *str, int *num);

t_dllist	*read_numbers(char **params, int pcount)
{
	char		**nums;
	int			error;
	t_dllist	*dllist;

	dllist = create_dllist();
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
	}
	return (dllist);
}

static int	parse_strs(char **strs, t_dllist *l)
{
	int	i;
	int	error;
	int	tmp;

	i = 0;
	error = 0;
	while (!error && strs[i])
	{
		error = ft_atoi_safe(strs[i++], &tmp) || dllist_find(l, node_matches,
				tmp) != NULL || dllist_push_back(l, tmp);
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs[i]);
	free(strs);
	return (error);
}

static int	node_matches(int val, int oval)
{
	return (val == oval);
}
