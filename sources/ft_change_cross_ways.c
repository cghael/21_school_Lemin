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

//	lemin->graph[tmp_p->next->from].links[tmp_p->next->to].way = 0;
//	lemin->graph[tmp_p->next->to].links[tmp_p->next->from].way = 0;
//	tmptmp_p = tmp_p->next;
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
	}
	tmp_p->next = tmptmp_cur;
	tmp_cur->next = tmptmp_p;
	ft_make_new_way_links(lemin, tmp_p->next, tmp_cur->next);
//	free(tmptmp_cur);
//	free(tmptmp_p);
}

static void ft_print_p(t_path *path, t_lemin *lemin)
{
	t_path *tmp;

	tmp = path;
	while (tmp)
	{
		ft_printf("%s-%s ", lemin->graph[tmp->from].name, lemin->graph[tmp->to].name);
		tmp = tmp->next;
	}
	ft_printf("\n");
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
//		cross_end = cross_end->next;
	return (tmp);
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
//		if (current->cross->num == 15)
//			ft_printf("%d\n", current->cross->num);
		cross_end = ft_check_cross_length(current->cross);
//		ft_printf("\ncurrent->path: \n"); //todo del
//		ft_print_p(current->path, lemin); //todo del
//		ft_printf("\ncurrent->cross: \n"); //todo del
//		ft_print_p(current->cross, lemin); //todo del
		tmp_cur = current->path;
		while (tmp_cur && tmp_cur->next->to != cross_end->from \
				&& tmp_cur->next->from != cross_end->to)
			tmp_cur = tmp_cur->next;
//		ft_printf("\ntmp_cur = %d-%d\n", tmp_cur->from, tmp_cur->to);
		tmp_tr = tracks;
//		if (current->cross->num == 15)
//			ft_printf("%d\n", current->cross->num);
		while (--current->cross->num > 0)
			tmp_tr = tmp_tr->next;
		tmp_p = tmp_tr->path;
//		ft_printf("\ntmp_tr->path: \n"); //todo del
//		ft_print_p(tmp_tr->path, lemin); //todo del
		while (current->cross->from != tmp_p->next->from \
				&& current->cross->to != tmp_p->next->to)
			tmp_p = tmp_p->next;
//		ft_printf("\ntmp_p = %d-%d\n", tmp_p->from, tmp_p->to);
		ft_change_path_parts(tmp_p, tmp_cur, lemin);
		current->cross = cross_end->next;
//		ft_printf("\ncurrent->path: \n"); //todo del
//		ft_print_p(current->path, lemin); //todo del
//		ft_printf("\ntmp_tr->path: \n"); //todo del
//		ft_print_p(tmp_tr->path, lemin); //todo del
	}
}
