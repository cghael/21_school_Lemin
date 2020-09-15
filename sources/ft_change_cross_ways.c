/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_cross_ways.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:47:25 by cghael            #+#    #+#             */
/*   Updated: 2020/09/14 13:47:27 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_change_path_parts(t_path *tmp_p, t_path *tmp_cur)
{
	t_path	*tmptmp_p;
	t_path	*tmptmp_cur;

	tmptmp_p = tmp_p->next;
	tmptmp_cur = tmp_cur->next;
	tmp_p->next = tmptmp_cur->next;
	tmp_cur->next = tmptmp_p->next;
	free(tmptmp_cur);
	free(tmptmp_p);
}

void		ft_change_cross_ways(t_tracks *current, t_tracks *tracks, t_lemin *lemin)
{
	t_tracks	*tmp_tr;
	t_path		*tmp_cur;
	t_path		*tmp_p;

	while (current->cross)
	{
		tmp_cur = current->path;
		while (tmp_cur->next->to != current->cross->from && tmp_cur->next->from != current->cross->to)
			tmp_cur = tmp_cur->next;
		tmp_tr = tracks;
		while (current->cross->num - 1 > 0)
		{
			tmp_tr = tmp_tr->next;
			current->cross->num--;
		}
		tmp_p = tmp_tr->path;
		while (current->cross->from != tmp_p->next->from && current->cross->to != tmp_p->next->to)
			tmp_p = tmp_p->next;
		ft_change_path_parts(tmp_p, tmp_cur);
		current->cross = current->cross->next;
	}
}
