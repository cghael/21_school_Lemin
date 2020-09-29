/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tracks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:17:32 by cghael            #+#    #+#             */
/*   Updated: 2020/09/07 12:17:33 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_free_path(t_path *path)
{
	t_path *tmp;

	while (path != NULL)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
}

void			ft_free_tracks(t_tracks *tracks)
{
	t_tracks	*tmp;

	if (tracks)
	{
		while (tracks)
		{
			tmp = tracks->next;
			ft_free_path(tracks->path);
			ft_free_path(tracks->cross);
			free(tracks->ants);
			tracks->path = NULL;
			free(tracks);
			tracks = tmp;
		}
	}
}
