/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:56 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/10 22:52:32 by zanikin          ###   ########.fr       */
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
	char			id;
}	t_dllist;

typedef struct s_onode
{
	t_dllist_node	*node;
	size_t			order;
}	t_onode;

typedef struct s_bypass
{
	size_t			depth;
	size_t			counter;
	t_dllist_node	*(*next)(t_dllist_node *);
	int				(*cont_cond)(t_bypass *, t_onode *);
	int				(*cond)(t_dllist_node *, t_bypass *, t_onode *);
	int				val;
	t_dllist_node	*(*init)(t_dllist_node *, t_bypass *, t_onode *);
}	t_bypass;

void			s_(t_dllist *l);
void			ss(t_dllist *a, t_dllist *b);
void			p_(t_dllist *to, t_dllist *from);
void			r_(t_dllist *l);
void			rr(t_dllist *a, t_dllist *b);
void			rr_(t_dllist *a);
void			rrr(t_dllist *a, t_dllist *b);

int				dllist_push_back(t_dllist *l, int val);
void			clear_dllist(t_dllist *l);
t_dllist		*create_dllist(char id);
int				dll_is_sorted(t_dllist *l);

void			dllist_bypass(t_dllist_node *node, t_bypass *bypass,
					t_onode *onode);
t_dllist_node	*first_match_init(t_dllist_node *node, t_bypass *bypass,
					t_onode *onode);
t_dllist_node	*last_match_init(t_dllist_node *node, t_bypass *bypass,
					t_onode *onode);
int				not_end_cont_cond(t_bypass *bypass, t_onode *onode);
int				matched_cont_cond(t_bypass *bypass, t_onode *onode);
t_dllist_node	*up_next(t_dllist_node *node);
t_dllist_node	*down_next(t_dllist_node *node);
int				val_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode);
int				gt_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode);
int				gt_next_cond(t_dllist_node *node, t_bypass *bypass,
					t_onode *onode);
int				eq_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode);
int				lt_cond(t_dllist_node *node, t_bypass *bypass, t_onode *onode);

void			dllist_find(t_dllist_node *start, size_t depth, int val,
					t_onode *res);
void			dllist_max(t_dllist_node *start, size_t depth,
					t_dllist_node *(*next)(t_dllist_node *), t_onode *res);
void	dllist_min(t_dllist_node *start, size_t depth,
			t_dllist_node *(*next)(t_dllist_node *), t_onode *res);

t_dllist		*read_numbers(char **params, int pcount);
#endif
