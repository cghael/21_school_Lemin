/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_one_step_solution.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:25:07 by cghael            #+#    #+#             */
/*   Updated: 2020/10/02 17:25:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_write_steps(t_lemin *lemin, t_tracks *tracks, t_tracks *tmp)
{
	int	ants;
	int	i;

	i = 1;
	ants = lemin->ants;
	ft_init_n_add_print(lemin, tracks);
	while (ants)
	{
		ft_init_n_add_step(lemin, i, tmp->path->to, tracks);
		ants--;
		i++;
	}
}

int			ft_find_one_step_solution(t_lemin *lemin, t_tracks *tracks)
{
	t_tracks	*tmp;

	tmp = tracks;
	while (tmp)
	{
		if (tmp->len == 1)
		{
			ft_write_steps(lemin, tracks, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
