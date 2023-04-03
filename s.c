/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:43:27 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/28 14:31:36 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void	swap(int *v, int n)
{
	int	temp;

	if (n < 2)
		return ;
	temp = v[n - 1];
	v[n - 1] = v[n - 2];
	v[n - 2] = temp;
}

void	swap_both(t_arr *s)
{
	swap(s->a, s->na);
	swap(s->b, s->nb);
	ft_printf("ss\n");
	s->count++;
}

void	swap_a(t_arr *s)
{
	swap(s->a, s->na);
	ft_printf("sa\n");
	s->count++;
}

void	swap_b(t_arr *s)
{
	swap(s->b, s->nb);
	ft_printf("sb\n");
	s->count++;
}
