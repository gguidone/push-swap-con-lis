/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:58:50 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 18:43:02 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	replace(int *a, int *tmp, int na)
{
	int	i;
	int	j;

	i = 0;
	while (i < na)
	{
		j = 0;
		while (j < na)
		{
			if (tmp[i] == a[j])
			{
				a[j] = i + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_replace(int *a, int na)
{
	int	*tmp;
	int	i;

	tmp = ft_calloc(na, sizeof(int));
	i = 0;
	while (i < na)
	{
		tmp[i] = a[i];
		i++;
	}
	quicksort(tmp, 0, na - 1);
	replace(a, tmp, na);
}

int	is_sorted(int *a, int na)
{
	int	i;

	i = 0;
	while (i < na - 1)
	{
		if (a[i] < a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_3(t_arr *s)
{
	if (is_sorted(s->a, s->na))
		return ;
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
		rev_rotate_a(s);
	else if (s->a[0] > s->a[2] && s->a[1] > s->a[0])
	{
		swap_a(s);
		rotate_a(s);
	}
	else if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		rotate_a(s);
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
	{
		swap_a(s);
		rev_rotate_a(s);
	}
	else if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		swap_a(s);
}
