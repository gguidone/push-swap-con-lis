/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:20:30 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/22 14:20:30 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H
# include "libft/libft.h"

typedef struct s_arr
{
	int	*a;
	int	na;
	int	*b;
	int	nb;
	int	count;
}t_arr;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}t_moves;

typedef struct s_lis
{
	int	*lis;
	int	nlis;
}t_lis;

void	print(int *v, int n);
/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void	swap(int *v, int n);
void	swap_both(t_arr *s);
void	swap_a(t_arr *s);
void	swap_b(t_arr *s);
/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
*/

void	push_a(t_arr *s);
void	push_b(t_arr *s);

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*/
void	rotate(int *a, int n);
void	rotate_both(t_arr *s);
void	rotate_a(t_arr *s);
void	rotate_b(t_arr *s);
/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
*/
void	rev_rotate(int *a, int na);
void	rev_rotate_both(t_arr *s);
void	rev_rotate_a(t_arr *s);
void	rev_rotate_b(t_arr *s);

int		ft_doubles(int *a, int na);
int		ft_check_errors(t_arr *s);
void	quicksort(int *a, int primo, int ultimo);
void	ft_replace(int *a, int na);
int		is_sorted(int *a, int na);
void	sort_3(t_arr *s);
int		mod(int a);
int		find_pos(int *a, int na, int to_insert);
void	sort_5(t_arr *s);
void	reach_pos(t_arr *s, int to_find);

void	first_step(t_arr *s);
void	first_step_ex(t_arr *s);
int		find_cluster_ex(int to_find, int s_na_start, int n_cluster);

t_moves	calc_moves(t_arr *s, int i);
void	n_moves(t_arr *s);

t_arr	*setup(int argc, char **argv);

t_lis	*max_lis(int *v, int n);
int		is_in_liss(t_lis *liss, int n);

#endif