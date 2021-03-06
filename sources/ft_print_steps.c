/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:49:47 by ksemele           #+#    #+#             */
/*   Updated: 2020/10/02 17:50:03 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_print_steps(t_lemin *lemin)
{
	t_print		*tmp_pr;
	t_step		*tmp_st;

	tmp_pr = lemin->print;
	while (tmp_pr)
	{
		tmp_st = tmp_pr->step;
		while (tmp_st)
		{
			ft_dprintf(lemin->fd_sol, "L%d-%s", tmp_st->ant, \
											lemin->graph[tmp_st->room].name);
			tmp_st = tmp_st->next;
			if (tmp_st)
				ft_dprintf(lemin->fd_sol, " ");
		}
		tmp_pr = tmp_pr->next;
		if (lemin->fd_sol == 1 || tmp_pr)
			ft_dprintf(lemin->fd_sol, "\n");
	}
	if (lemin->fd_sol > 1)
		ft_dprintf(1, "Solution saved to file %s\n", lemin->solname);
}
