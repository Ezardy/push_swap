/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:28:37 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/02 14:14:10 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

static int	parse_strs(char **strs, int *num_arr, int *place);
int			ft_atoi_safe(const char *str, int *num);

int	read_numbers(char **params, int pcount, int **num_arr)
{
	int		count;
	char	**nums;
	int		place;
	int		num_in_str;

	count = 0;
	*num_arr = NULL;
	place = 0;
	if (pcount)
	{
		*num_arr = (int *)malloc(sizeof(int) * pcount);
		count = - (num_arr == NULL);
		while (count != -1 && pcount--)
		{
			nums = ft_split(*params++, ' ');
			num_in_str = parse_strs(nums, *num_arr, &place);
			count = count * (num_in_str != -1) + num_in_str;
		}
	}
	if (count == -1)
	{
		free(*num_arr);
		*num_arr = NULL;
	}
	return (count);
}

static int	parse_strs(char **strs, int *num_arr, int *place)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (count != -1 && strs[i])
	{
		count = ft_atoi_safe(strs[i++], num_arr + *place) * -(count + 2)
			+ count + 1;
		if (count != -1)
		{
			j = 0;
			while (j < *place && num_arr[j] != num_arr[*place])
				j++;
			count = (j == *place) * (count + 1) - 1;
		}
		(*place)++;
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs[i]);
	free(strs);
	return (count);
}
