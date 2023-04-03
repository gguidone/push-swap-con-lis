/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:51:46 by gguidone          #+#    #+#             */
/*   Updated: 2023/04/03 15:41:19 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_lis	*lis_union(t_lis *mag, t_lis *min)
{
	t_lis	*result;
	int		i;
	int		j;

	result = calloc(1, sizeof(t_lis));
	result->nlis = mag->nlis + min->nlis - 1;
	result->lis = calloc(1, sizeof(int) * result->nlis);
	i = min->nlis - 1;
	j = 0;
	while (i >= 0)
	{
		result->lis[j] = min->lis[i];
		i--;
		j++;
	}
	i = 1;
	while (i < mag->nlis)
	{
		result->lis[j] = mag->lis[i];
		i++;
		j++;
	}
	return (result);
}

t_lis	*create_lis(int n)
{
	t_lis	*s;

	s = calloc(1, sizeof(t_lis));
	s->nlis = 1;
	s->lis = calloc(1, sizeof(int) * n);
	return (s);
}

void	free_lis(t_lis *s)
{
	free(s->lis);
	free(s);
}

t_lis	*find_lis(int *v, int n, int i)
{
	int		j;
	t_lis	*lis_mag;
	t_lis	*lis_min;
	t_lis	*result;

	lis_mag = create_lis(n);
	j = i;
	lis_mag->lis[0] = v[i];
	while (++j < n)
		if (lis_mag->lis[lis_mag->nlis - 1] > v[j])
			lis_mag->lis[lis_mag->nlis++] = v[j];
	lis_min = create_lis(n);
	j = i;
	lis_min->lis[0] = v[i];
	while (--j >= 0)
		if (lis_min->lis[lis_min->nlis - 1] < v[j])
			lis_min->lis[lis_min->nlis++] = v[j];
	result = lis_union(lis_mag, lis_min);
	free_lis(lis_mag);
	free_lis(lis_min);
	return (result);
}

t_lis	*copy_lis(t_lis *dst, t_lis *src)
{
	int	i;

	i = 0;
	free(dst);
	dst = create_lis(src->nlis);
	dst->nlis = src->nlis;
	while (i < src->nlis)
	{
		dst->lis[i] = src->lis[i];
		i++;
	}
	return (dst);
}

t_lis	*max_lis(int *v, int n)
{
	t_lis	*max;
	t_lis	*tmp;
	int		i;

	i = 0;
	max = create_lis(n);
	tmp = create_lis(n);
	while (i < n)
	{
		tmp = find_lis(v, n, i);
		if (tmp->nlis > max->nlis)
			copy_lis(max, tmp);
		i++;
	}
	return (max);
}

int is_in_liss(t_lis *liss, int n)
{
	int	i;

	i = 0;
	while (i < liss->nlis)
	{
		if (liss->lis[i] == n)
			return (1);
		i++;
	}
	return (0);
}
