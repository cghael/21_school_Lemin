/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:46:15 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:46:17 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*ft_parse_data(t_lemin *lemin)
{
	t_data	*data;

	data = NULL;
	ft_parse_ants(lemin, &data);
//	ft_parse_rooms(lemin, &data);
	return (lemin);
}
