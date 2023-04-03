/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:12:16 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/30 17:17:50 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

int	is_max(int *a, int na, int to_insert)
{
	int	i;
	int	flag;
	int	pos_min;
	int	min;

	i = 0;
	flag = 1;
	pos_min = 0;
	min = -5000;
	while (i < na && flag)
	{
		if (a[i] - to_insert > 0)
			flag = 0;
		if (a[i] - to_insert > min)
		{
			pos_min = i;
			min = a[i] - to_insert;
		}
		i++;
	}
	if (flag == 0)
		return (-1);
	else
		return (pos_min);
}

int	find_pos(int *a, int na, int to_insert)
{
	int	i;
	int	diff;
	int	pos;

	diff = 5000;
	i = 0;
	pos = 0;
	if (is_max(a, na, to_insert) != -1)
		return (is_max(a, na, to_insert));
	while (i < na)
	{
		if (a[i] - to_insert < diff && a[i] - to_insert > 0)
		{
			diff = a[i] - to_insert;
			pos = i + 1;
		}
		i++;
	}
	return (pos);
}

void	reach_pos(t_arr *s, int to_find)
{
	int	pos;

	pos = find_pos(s->a, s->na, to_find);
	if (pos >= s->na / 2)
	{
		while (s->a[s->na - 1] != to_find)
			rotate_a(s);
	}
	else
	{
		while (s->a[s->na - 1] != to_find)
			rev_rotate_a(s);
	}
}

void	sort_5(t_arr *s)
{
	int	pos;

	push_b(s);
	push_b(s);
	sort_3(s);
	while (s->nb)
	{
	pos = find_pos(s->a, s->na, s->b[s->nb - 1]);
		if (pos >= (float)s->na / 2)
		{
			pos = s->na - pos;
			while (pos--)
				rev_rotate_a(s);
			push_a(s);
		}
		else
		{
			while (pos--)
				rotate_a(s);
			push_a(s);
		}
	}
	reach_pos(s, s->na);
}
