/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:34:46 by cghael            #+#    #+#             */
/*   Updated: 2020/09/02 12:34:48 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_parse_links(t_lemin *lemin, t_data **data)
{
	while ((*data)->back->content && ft_is_link(data, lemin) == 1)
	{
		if (ft_get_data(data) == -1)
			ft_error_n_exit(
					"Error in ft_parse_links()\n",
					lemin,
					data,
					NULL);
		if (!ft_strlen((*data)->back->content))
		{
			if (ft_get_data(data))
				ft_error_n_exit(
						LINK_NOT_VALID,
						lemin,
						data,
						NULL);
			else
				return ;
		}
	}
	ft_error_n_exit(
			LINK_NOT_VALID,
			lemin,
			data,
			NULL);
}
