/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:16:45 by cghael            #+#    #+#             */
/*   Updated: 2020/09/04 15:16:46 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_tracks		*ft_create_tracks(void)
{
	t_tracks	*tracks;

	tracks = NULL;
	if ((tracks = ft_memalloc(sizeof(t_tracks))) == NULL)
		return (NULL);
	tracks->next = NULL;
	tracks->path = NULL;
	return (tracks);
}

static t_tracks		*ft_create_new_track(t_tracks **tracks)
{
	t_tracks	*current;
	t_tracks	*tmp;

	if (*tracks == NULL)
	{
		if ((*tracks = ft_create_tracks()) == NULL)
			return (NULL);
		current = *tracks;
	}
	else
	{
		if ((current = ft_create_tracks()) == NULL)
			return (NULL);
		tmp = *tracks;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = current;
	}
	return (current);
}

static int			ft_count_path_len(t_path *path)
{
	int		len;
	t_path	*tmp;

	len = 0;
	tmp = path;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len); //count steps
}

static void			ft_clear_lvls(t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < lemin->rooms)
	{
		lemin->graph[i].level = 0;
		i++;
	}
}

void				ft_find_paths(t_lemin *lemin)
{
	int			lvl;
	t_tracks	*tracks;
	t_tracks	*current;
	t_return	ret;

	lvl = 0;
	tracks = NULL;
	while (lvl >= 0)
	{
		if ((lvl = ft_set_levels(lemin, 0)) < 0)
			break ; //todo no more ways
		ft_print_matrix(lemin->graph, lemin->rooms, 0); //todo del
		current = ft_create_new_track(&tracks);
		ret = ft_write_path(lemin, lvl, &current->path);
		if (EXIT_FAILURE == ret.res)
			ft_error_n_exit("Error in ft_find_paths()\n", lemin, NULL, tracks);
		current->len = ft_count_path_len(current->path);
		//todo if ret.cross == 1 !!!
		ft_print_matrix(lemin->graph, lemin->rooms, 1); //todo del
		ft_print_path(lemin->graph, current->path, current->len); //todo del
		ft_clear_lvls(lemin);
//		lvl = -1;
	}
}
