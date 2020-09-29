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
	t_path	*del;

	tmptmp_p = tmp_p->next;
	while (tmptmp_p->from != tmp_cur->to)
	{
		del = tmptmp_p;
		lemin->graph[tmptmp_p->from].links[tmptmp_p->to].way = 0;
		lemin->graph[tmptmp_p->to].links[tmptmp_p->from].way = 0;
		tmptmp_p = tmptmp_p->next;
		free(del);
		del = NULL;
	}
	tmptmp_cur = tmp_cur->next;
	while (tmptmp_cur->from != tmp_p->to)
	{
		del = tmptmp_cur;
		tmptmp_cur = tmptmp_cur->next;
		free(del);
		del = NULL;
	}
	tmp_p->next = tmptmp_cur;
	tmp_cur->next = tmptmp_p;
	ft_make_new_way_links(lemin, tmp_p->next, tmp_cur->next);
}

static t_path	*ft_check_cross_length(t_path *cross)
{
	t_path	*cross_end;
	t_path	*tmp;

	tmp = cross;
	if (!tmp->next)
		return (tmp);
	cross_end = cross->next;
	while (cross_end && cross_end->from == tmp->to && cross_end->num == tmp->num)
	{
		cross_end = cross_end->next;
		tmp = tmp->next;
	}
	return (tmp);
}

static void		ft_free_cross_part(t_tracks *current, t_path *end)
{
	t_path	*tmp;

	while (current->cross != end)
	{
		tmp = current->cross;
		current->cross = current->cross->next;
		free(tmp);
	}
}

void			ft_change_cross_ways(t_tracks *current, t_tracks *tracks, \
																t_lemin *lemin)
{
	t_tracks	*tmp_tr;
	t_path		*tmp_cur;
	t_path		*tmp_p;
	t_path		*cross_end;

	while (current->cross)
	{
		cross_end = ft_check_cross_length(current->cross);
		tmp_cur = current->path;
		while (tmp_cur && tmp_cur->next->to != cross_end->from \
				&& tmp_cur->next->from != cross_end->to)
			tmp_cur = tmp_cur->next;
		tmp_tr = tracks;
		while (--current->cross->num > 0)
			tmp_tr = tmp_tr->next;
		tmp_p = tmp_tr->path;
		while (current->cross->from != tmp_p->next->from \
				&& current->cross->to != tmp_p->next->to)
			tmp_p = tmp_p->next;
		ft_change_path_parts(tmp_p, tmp_cur, lemin);
		ft_free_cross_part(current, cross_end->next);
	}
}
