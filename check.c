/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:22:34 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 16:13:14 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include <stdlib.h>

int	ft_doubles(int *a, int na)
{
	int	i;
	int	j;

	i = 0;
	while (i < na - 1)
	{
		j = i + 1;
		while (j < na)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_errors(t_arr *s)
{
	if (s == NULL)
	{
		ft_printf("1");
		return (1);
	}
	if (s->nb > 0)
	{
		ft_printf("2");
		return (1);
	}
	if (ft_doubles(s->a, s->na))
	{
		ft_printf("3");
		return (1);
	}
	return (0);
}

void	qswap(int *a, int i, int j)
{
	int	temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void	quicksort(int *a, int primo, int ultimo)
{
	int	i;
	int	j;
	int	pivot;

	if (primo < ultimo)
	{
		pivot = primo;
		i = primo;
		j = ultimo;
		while (i < j)
		{
			while (a[i] <= a[pivot] && i < ultimo)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i < j)
				qswap(a, i, j);
		}
		qswap(a, pivot, j);
		quicksort(a, primo, j - 1);
		quicksort(a, j + 1, ultimo);
	}
}
