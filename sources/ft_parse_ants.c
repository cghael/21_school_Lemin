/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:57:17 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:57:19 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_parse_ants(t_lemin *lemin, t_data **data)
{
	while (lemin->ants == 0)
	{
		if (ft_get_data(data) < 1)
			ft_error_n_exit(
					"Error in ft_parse_ants()\n",
					lemin,
					data,
					NULL);
		if (!ft_str_is_int((*data)->back->content) \
			&& (*data)->back->content[0] != '#')
			ft_error_n_exit(
					BAD_INPUT,
					lemin,
					data,
					NULL);
		else if ((*data)->back->content[0] != '#')
		{
			lemin->ants = ft_atoi((*data)->back->content);
			if (lemin->ants < 1)
				ft_error_n_exit(
						ANTS_NOT_VALID,
						lemin,
						data,
						NULL);
		}
	}
}
