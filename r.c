/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:43:34 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 19:26:01 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*/
void	rotate(int *a, int n)
{
	int	temp;
	int	i;

	temp = a[n - 1];
	i = n - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
}

void	rotate_both(t_arr *s)
{
	rotate(s->a, s->na);
	rotate(s->b, s->nb);
	ft_printf("rr\n");
	s->count++;
}

void	rotate_a(t_arr *s)
{
	rotate(s->a, s->na);
	ft_printf("ra\n");
	s->count++;
}

void	rotate_b(t_arr *s)
{
	rotate(s->b, s->nb);
	ft_printf("rb\n");
	s->count++;
}
