/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:21:20 by zanikin           #+#    #+#             */
/*   Updated: 2024/04/18 01:02:22 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	exec_push_swap_instr(t_dllist *a, t_dllist *b, char *instr);
static int	exec_rotate_instr(t_dllist *a, t_dllist *b, char *instr);
static int	exec_instr(t_dllist *a, t_dllist *b);
static void	print_result(t_dllist *a, t_dllist *b);

int	main(int argc, char **argv)
{
	int			error;
	t_dllist	*a;
	t_dllist	*b;

	error = 1;
	a = read_numbers(argv + 1, argc - 1);
	if (a && (a->size || argc == 1))
	{
		b = create_dllist('b');
		if (b)
		{
			error = exec_instr(a, b);
			if (!error)
				print_result(a, b);
			clear_dllist(b);
			free(b);
		}
		clear_dllist(a);
		free(a);
	}
	if (error)
		ft_putstr_fd("Error\n", 2);
	return (error);
}

static void	print_result(t_dllist *a, t_dllist *b)
{
	if (b->size || !dll_is_sorted(a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
}

static int	exec_instr(t_dllist *a, t_dllist *b)
{
	int		error;
	char	*instr;

	instr = get_next_line(0);
	error = 0;
	while (!error && instr)
	{
		error = !(exec_push_swap_instr(a, b, instr)
				|| exec_rotate_instr(a, b, instr));
		free(instr);
		instr = get_next_line(0);
	}
	return (error);
}

static int	exec_push_swap_instr(t_dllist *a, t_dllist *b, char *instr)
{
	int	executed;

	executed = 1;
	if (!ft_strncmp(instr, "pa\n", 3))
		p_(a, b);
	else if (!ft_strncmp(instr, "pb\n", 3))
		p_(b, a);
	else if (!ft_strncmp(instr, "sa\n", 3))
		s_(a);
	else if (!ft_strncmp(instr, "sb\n", 3))
		s_(b);
	else if (!ft_strncmp(instr, "ss\n", 3))
		ss(a, b);
	else
		executed = 0;
	return (executed);
}

static int	exec_rotate_instr(t_dllist *a, t_dllist *b, char *instr)
{
	int	executed;

	executed = 1;
	if (!ft_strncmp(instr, "ra\n", 3))
		r_(a);
	else if (!ft_strncmp(instr, "rb\n", 3))
		r_(b);
	else if (!ft_strncmp(instr, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(instr, "rra\n", 4))
		rr_(a);
	else if (!ft_strncmp(instr, "rrb\n", 4))
		rr_(b);
	else if (!ft_strncmp(instr, "rrr\n", 4))
		rrr(a, b);
	else
		executed = 0;
	return (executed);
}
