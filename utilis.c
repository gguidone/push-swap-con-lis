/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:10:27 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 19:45:19 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_moves	calc_moves(t_arr *s, int i)
{
	int		pos;
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rra = 0;
	moves.rrb = 0;
	pos = find_pos(s->a, s->na, s->b[i]);
	if (pos >= s->na / 2)
		moves.ra = s->na - pos;
	else
		moves.rra += pos;
	if (i >= s->nb / 2)
		moves.rb = s->nb - i - 1;
	else
		moves.rrb = i + 1;
	return (moves);
}

int	c_moves(t_moves *moves, int i) // valore assoluto per combo
{
	int	count;

	count = 0;
	while (moves[i].ra > 0 && moves[i].rb > 0)
	{
		count++;
		moves[i].ra -= 1;
		moves[i].rb -= 1;
	}
	while (moves[i].rra > 0 && moves[i].rrb > 0)
	{
		count++;
		moves[i].rra -= 1;
		moves[i].rrb -= 1;
	}
	while (moves[i].ra > 0)
	{
		count++;
		moves[i].ra -= 1;
	}
	while (moves[i].rb > 0)
	{
		count++;
		moves[i].rb -= 1;
	}
	while (moves[i].rra > 0)
	{
		count++;
		moves[i].rra -= 1;
	}
	while (moves[i].rrb > 0)
	{
		count++;
		moves[i].rrb -= 1;
	}
	return (count);
}

int	find_min(t_moves *s, int size)
{
	int	pos_min;
	int	i;
	int	min;

	i = 1;
	pos_min = 0;
	min = c_moves(s, 0);
	while (i < size)
	{
		if (c_moves(s, i) < min)
		{
			min = c_moves(s, i);
			pos_min = i;
		}
		i++;
	}
	return (pos_min);
}

void	n_moves(t_arr *s)
{
	t_moves	*moves;
	int		i;

	i = 0;
	moves = ft_calloc(1, sizeof(t_moves) * s->nb);
	//ft_printf("\t ra rb rra rrb\n");
	while (i < s->nb)
	{
		moves[i] = calc_moves(s, i);
		//ft_printf("elem %i pos %i: %i %i %i %i\n", s->b[i], i, moves[i].ra, moves[i].rb, moves[i].rra, moves[i].rrb);
		i++;
	}
	i = find_min(moves, s->nb);
	//ft_printf("min in pos %i\n", i);
	moves[i] = calc_moves(s, i);
	while (moves[i].ra > 0 && moves[i].rb > 0)
	{
		rotate_both(s);
		moves[i].ra -= 1;
		moves[i].rb -= 1;
	}
	while (moves[i].rra > 0 && moves[i].rrb > 0)
	{
		rev_rotate_both(s);
		moves[i].rra -= 1;
		moves[i].rrb -= 1;
	}
	while (moves[i].ra > 0)
	{
		rotate_a(s);
		moves[i].ra -= 1;
	}
	while (moves[i].rb > 0)
	{
		rotate_b(s);
		moves[i].rb -= 1;
	}
	while (moves[i].rra > 0)
	{
		rev_rotate_a(s);
		moves[i].rra -= 1;
	}
	while (moves[i].rrb > 0)
	{
		rev_rotate_b(s);
		moves[i].rrb -= 1;
	}
	push_a(s);
	free(moves);
}
