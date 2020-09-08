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

static void	ft_free_path(t_path *path)
{
	t_path *tmp;

	while (path != NULL)
	{
		tmp = path->next;
		free(path->name);
		free(path);
		path = tmp;
	}
}

void		ft_free_tracks(t_tracks *tracks)
{
	if (tracks)
	{
		while (tracks)
		{
			ft_free_path(tracks->path);
			tracks = tracks->next;
		}
	}
}
