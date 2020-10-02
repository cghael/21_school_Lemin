/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_n_add_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:29:48 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:29:49 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init_n_add_step(t_lemin *lemin, int ant, int room, t_tracks *tracks)
{
	t_step	*tmp;
	t_step	*begin_step;
	t_print	*begin_print;

	tmp = ft_memalloc(sizeof(t_step));
	if (tmp == NULL)
		ft_error_n_exit("Error in ft_init_n_add_step()\n", lemin, NULL, tracks);
	tmp->next = NULL;
	tmp->ant = ant;
	tmp->room = room;
	begin_print = lemin->print;
	while (begin_print->next)
		begin_print = begin_print->next;
	if (!begin_print->step)
		begin_print->step = tmp;
	else
	{
		begin_step = begin_print->step;
		while (begin_step->next)
			begin_step = begin_step->next;
		begin_step->next = tmp;
	}
}

void	ft_init_n_add_print(t_lemin *lemin, t_tracks *tracks)
{
	t_print *tmp;
	t_print *begin;

	tmp = ft_memalloc(sizeof(t_print));
	if (tmp == NULL)
		ft_error_n_exit("Error in ft_init_n_add_print()\n", lemin, NULL, tracks);
	tmp->next = NULL;
	tmp->step = NULL;
	if (!lemin->print)
		lemin->print = tmp;
	else
	{
		begin = lemin->print;
		while (begin->next)
			begin = begin->next;
		begin->next = tmp;
	}
}
