/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:51:02 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/29 19:17:08 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

int	main(int argc, char **argv)
{
	t_arr	*s;

	s = setup(argc, argv);
	if (ft_check_errors(s))
		ft_printf("Errore\n"); //aggiungi exit
	else
	{
	ft_replace(s->a, s->na);
	ft_printf("A: ");
	print(s->a, s->na);
	if (s->na == 3)
		sort_3(s);
	else if (s->na == 5)
		sort_5(s);
	else
		first_step_ex(s);
	ft_printf("A: ");
	print(s->a, s->na);
	ft_printf("B: ");
	print(s->b, s->nb);
	ft_printf("moves = %i \n", s->count);
	free(s); // fai il free dell array nella struttura
	}
	/*int a[3] = {20, 19, 15};
	int to_find = 3;
	ft_printf("%i", find_pos(a, 3, to_find));*/
	return (0);
}
