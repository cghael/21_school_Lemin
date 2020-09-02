/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lemin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:45:41 by cghael            #+#    #+#             */
/*   Updated: 2020/09/02 15:45:43 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_free_lemin(t_lemin *lemin)
{
	int i;

	i = 0;
	if (lemin)
	{
		if (lemin->graph)
		{
			while (i < lemin->rooms)
			{
				if (lemin->graph[i].name)
					free(lemin->graph[i].name);
				if (lemin->graph[i].links)
					free(lemin->graph[i].links);
				i++;
			}
			free(lemin->graph);
		}
		free(lemin);
	}
}
