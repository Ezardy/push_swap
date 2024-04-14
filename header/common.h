/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:56 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/14 22:59:53 by zanikin          ###   ########.fr       */
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
	size_t					order;
	int						val;
}	t_dllist_node;

typedef struct s_dllist
{
	t_dllist_node	*top;
	size_t			size;
	char			id;
	int				ordered;
}	t_dllist;

typedef struct s_bypass
{
	t_dllist_node	*cur;
	t_dllist_node	*(*next)(t_bypass *);
	t_dllist_node	*(*init)(t_dllist_node *, t_bypass *);
	t_dllist_node	*(*action)(t_bypass *);
	size_t			counter;
	size_t			depth;
	int				(*cont_cond)(t_bypass *, t_dllist_node *);
	int				(*cond)(t_bypass *);
	int				val;
}	t_bypass;

void			s_(t_dllist *l);
void			ss(t_dllist *a, t_dllist *b);
void			p_(t_dllist *to, t_dllist *from);
void			r_(t_dllist *l);
void			rr(t_dllist *a, t_dllist *b);
void			rr_(t_dllist *a);
void			rrr(t_dllist *a, t_dllist *b);

t_dllist		*create_dllist(char id);
void			clear_dllist(t_dllist *l);
void			dll_numerate(t_dllist *l);
int				dllist_push_back(t_dllist *l, int val);
int				dll_is_sorted(t_dllist *l);

t_dllist_node	*dllist_bypass(t_dllist_node *node, t_bypass *bypass);
t_dllist_node	*first_match_init(t_dllist_node *node, t_bypass *bypass);
t_dllist_node	*last_match_init(t_dllist_node *node, t_bypass *bypass);
t_dllist_node	*count_action(t_bypass *bypass);
t_dllist_node	*assign_action(t_bypass *bypass);
void			up_next(t_bypass *bypass);
void			down_next(t_bypass *bypass);
int				not_end_cont_cond(t_bypass *bypass, t_dllist_node *cur_res);
int				matched_cont_cond(t_bypass *bypass, t_dllist_node *cur_res);
int				gt_cond(t_bypass *bypass);
int				gt_next_cond(t_bypass *bypass);
int				eq_cond(t_bypass *bypass);
int				lt_cond(t_bypass *bypass);
int				true_cond(t_bypass *bypass);

t_dllist_node	*dllist_find(t_dllist_node *start, size_t depth, int val);
t_dllist_node	*dllist_max(t_dllist_node *start, size_t depth,
					t_dllist_node *(*next)(t_dllist_node *));
t_dllist_node	*dllist_min(t_dllist_node *start, size_t depth,
					t_dllist_node *(*next)(t_dllist_node *));
t_dllist_node	*dllist_bigger(t_dllist_node *start, size_t depth, int val,
					t_dllist_node *(*next)(t_dllist_node *));

t_dllist		*read_numbers(char **params, int pcount);
#endif
