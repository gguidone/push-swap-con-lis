/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:20:37 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/22 14:20:37 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	print(int *v, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("%i ", v[i]);
		i++;
	}
	ft_printf("\n");
}

void	push_a(t_arr *s)
{
	s->nb = s->nb - 1;
	s->a[s->na] = s->b[s->nb];
	s->na += 1;
	ft_printf("pa\n");
	s->count++;
}

void	push_b(t_arr *s)
{
	s->na = s->na - 1;
	s->b[s->nb] = s->a[s->na];
	s->nb += 1;
	ft_printf("pb\n");
	s->count++;
}
