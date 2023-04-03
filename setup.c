/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:44:53 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 12:18:00 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

int	matrix_is_num(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_arr	*setup(int argc, char **argv)
{
	t_arr	*s;
	int		i;

	if (matrix_is_num(argc, argv))
		return (NULL);
	s = ft_calloc(1, sizeof(t_arr));
	s->na = argc - 1;
	s->nb = 0;
	s->a = ft_calloc(1, sizeof(int) * s->na);
	s->b = ft_calloc(1, sizeof(int) * s->na);
	i = 0;
	while (i < argc)
	{
		s->a[i] = ft_atoi(argv[argc - 1 - i]);
		i++;
	}
	return (s);
}
