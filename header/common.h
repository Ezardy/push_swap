/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:56 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/05 21:12:46 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# ifndef PRINT_STACK_ACTIONS
#  define PRINT_STACK_ACTIONS 0
# endif

# include "libft/libft.h"

typedef struct s_dllist_node
{
	struct s_dllist_node	*next;
	struct s_dllist_node	*prev;
	int						val;
}	t_dllist_node;

typedef struct s_dllist
{
	t_dllist_node	*top;
	size_t			size;
}	t_dllist;

void			sa(t_dllist *a);
void			sb(t_dllist *b);
void			ss(t_dllist *a, t_dllist *b);
void			pa(t_dllist *a, t_dllist *b);
void			pb(t_dllist *a, t_dllist *b);
void			ra(t_dllist *a);
void			rb(t_dllist *a);
void			rr(t_dllist *a, t_dllist *b);
void			rra(t_dllist *a);
void			rrb(t_dllist *b);
void			rrr(t_dllist *a, t_dllist *b);

int				dllist_push_back(t_dllist *l, int val);
void			clear_dllist(t_dllist *l);
t_dllist		*create_dllist(void);
t_dllist_node	*dllist_find(t_dllist *l, int (*cond)(int, int), int val);
void			dllist_iter(t_dllist *l, void (*fun)(int));
int				dll_is_sorted(t_dllist *l);

t_dllist		*read_numbers(char **params, int pcount);
#endif
