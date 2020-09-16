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

static void	ft_make_new_way_links(t_lemin *lemin, t_path *tmp1, t_path *tmp2)
{
	int		way1;
	int		way2;

	way1 = lemin->graph[tmp1->from].links[tmp1->to].way;
	way2 = lemin->graph[tmp2->from].links[tmp2->to].way;
	while (tmp1)
	{
		lemin->graph[tmp1->from].links[tmp1->to].way = way2;
		lemin->graph[tmp1->to].links[tmp1->from].way = -way2;
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		lemin->graph[tmp2->from].links[tmp2->to].way = way1;
		lemin->graph[tmp2->to].links[tmp2->from].way = -way1;
		tmp2 = tmp2->next;
	}
}

static void	ft_change_path_parts(t_path *tmp_p, t_path *tmp_cur, t_lemin *lemin)
{
	t_path	*tmptmp_p;
	t_path	*tmptmp_cur;

	lemin->graph[tmp_p->next->from].links[tmp_p->next->to].way = 0;
	lemin->graph[tmp_p->next->to].links[tmp_p->next->from].way = 0;
	tmptmp_p = tmp_p->next;
	tmptmp_cur = tmp_cur->next;
	tmp_p->next = tmptmp_cur->next;
	tmp_cur->next = tmptmp_p->next;
	ft_make_new_way_links(lemin, tmp_p->next, tmp_cur->next);
	free(tmptmp_cur);
	free(tmptmp_p);
}

void		ft_change_cross_ways(t_tracks *current, t_tracks *tracks, \
																t_lemin *lemin)
{
	t_tracks	*tmp_tr;
	t_path		*tmp_cur;
	t_path		*tmp_p;

	while (current->cross)
	{
		tmp_cur = current->path;
		while (tmp_cur->next->to != current->cross->from \
				&& tmp_cur->next->from != current->cross->to)
			tmp_cur = tmp_cur->next;
		tmp_tr = tracks;
		while (current->cross->num - 1 > 0)
		{
			tmp_tr = tmp_tr->next;
			current->cross->num--;
		}
		tmp_p = tmp_tr->path;
		while (current->cross->from != tmp_p->next->from \
				&& current->cross->to != tmp_p->next->to)
			tmp_p = tmp_p->next;
		ft_change_path_parts(tmp_p, tmp_cur, lemin);
		current->cross = current->cross->next;
	}
}
