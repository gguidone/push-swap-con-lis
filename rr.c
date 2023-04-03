/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:43:38 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 18:00:51 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	rev_rotate(int *a, int n)
{
	int	temp;
	int	i;

	temp = a[0];
	i = 0;
	while (i < n - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[n - 1] = temp;
}

void	rev_rotate_both(t_arr *s)
{
	rev_rotate(s->a, s->na);
	rev_rotate(s->b, s->nb);
	ft_printf("rrr\n");
	s->count++;
}

void	rev_rotate_a(t_arr *s)
{
	rev_rotate(s->a, s->na);
	ft_printf("rra\n");
	s->count++;
}

void	rev_rotate_b(t_arr *s)
{
	rev_rotate(s->b, s->nb);
	ft_printf("rrb\n");
	s->count++;
}
