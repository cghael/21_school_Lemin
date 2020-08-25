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
	if (ft_get_data(data))
	{
		ft_free_data(*data);
		ft_error_n_exit("Error in ft_parse_ants()", lemin, LEMIN);
	}
}