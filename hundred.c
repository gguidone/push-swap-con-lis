/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:30:52 by gguidone          #+#    #+#             */
/*   Updated: 2023/04/03 15:38:43 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

int	find_cluster_ex(int to_find, int s_na_start, int n_cluster)
{
	if (to_find > 0 && to_find <= (s_na_start) / n_cluster)
		return (1);
	if (to_find > (s_na_start) / n_cluster && to_find <= 2 * (s_na_start) / n_cluster)
		return (2);
	return (3);
}

void	first_step_ex(t_arr *s)
{
	int		s_na_start;
	int		n_cluster;
	t_lis	*liss;
	
	liss = max_lis(s->a, s->na);
	n_cluster = 3;
	s_na_start = s->na;
	while (s->na != (s_na_start - liss->nlis) / n_cluster + liss->nlis)
	{
		if (is_in_liss(liss, s->a[s->na - 1]))
			rotate_a(s);
		else if (find_cluster_ex(s->a[s->na - 1], s_na_start, 3) == 1)
		{
			//ft_printf("1 elem %i is in cluster %i\n", s->a[s->na], find_cluster_ex(s->a[s->na - 1], s_na_start, n_cluster));
			push_b(s);
			if (s->nb - 2 >= 0 && find_cluster_ex(s->b[s->nb - 2], s_na_start, n_cluster) == 2)
				rotate_b(s);
		}
		else if (find_cluster_ex(s->a[s->na - 1], s_na_start, n_cluster) == 2)
		{
			//ft_printf("2 elem %i is in cluster %i\n", s->a[s->na], find_cluster_ex(s->a[s->na - 1], s_na_start, n_cluster));
			push_b(s);
		}
		else
		{
			//ft_printf("3 elem %i is in cluster %i\n", s->a[s->na], find_cluster_ex(s->a[s->na - 1], s_na_start, n_cluster));
			rotate_a(s);
		}
	}
	//while (s->na != 3)
	//	push_b(s);
	//sort_3(s);
	while (s->na != liss->nlis)
	{
		if (is_in_liss(liss, s->a[s->na - 1]))
			rotate_a(s);
		else 
			push_b(s);
	}
	print(s->a, s->na);
	while (s->nb)
		n_moves(s);
	reach_pos(s, 1);
	//ft_printf("Liss: ");
	//print(liss->lis, liss->nlis);
}

