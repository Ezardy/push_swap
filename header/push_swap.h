/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:15:40 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/17 16:37:51 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define R_ 1
# define RR_ 2
# define S_ 4
# define OI_ 0
# include "common.h"

typedef struct s_scheme
{
	int				is_upper;
	int				from_scheme;
	int				to_scheme;
	size_t			from_count;
	size_t			to_count;
	size_t			moves_count;
	t_dllist_node	*to_node;
	t_dllist_node	*from_node;
}	t_scheme;

typedef struct s_dll_pivoted
{
	t_dllist		*l;
	t_dllist_node	*upper;
	t_dllist_node	*pivot;
	t_dllist_node	*lower;
}	t_dll_pivoted;

void	pop_to(t_dllist *from, t_dllist *to);
void	rot_to_bottom(t_dllist *l, t_dllist_node *node);
void	rot_to_top(t_dllist *l, t_dllist_node *node);
size_t	dist(t_dll_pivoted *pl, int u);
size_t	ft_max(size_t a, size_t b);
size_t	ft_min(size_t a, size_t b);
void	select_scheme(t_scheme *sdata, size_t f_s, size_t t_s, size_t f_o);
void	select_upper_scheme(t_dllist *a, t_dll_pivoted *b, t_scheme *scheme);
void	execute_scheme(t_dllist *a, t_dll_pivoted *b, t_scheme *scheme);
void	func_c(t_dllist *l, void (*func)(t_dllist *), size_t count);
void	func2_c(t_dllist *a, t_dllist *b, void (*func2)(t_dllist *, t_dllist *),
			size_t count);
int		pick_upper_or_lower(t_dllist *a, t_dll_pivoted *b, size_t stock);
#endif
