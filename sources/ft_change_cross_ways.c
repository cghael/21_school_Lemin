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

void		ft_change_cross_ways(t_tracks *current, t_tracks *tracks)
{
	t_tracks	*tmp;

	while (current->cross)
	{
		current->cross = current->cross->next;
	}
}
