/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:13:49 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 14:13:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_free_data(t_data **data)
{
	t_data	*tmp;
	int		counter;

	if (*data)
	{
		counter = (*data)->counter;
		while (counter && *data)
		{
			tmp = (*data)->next;
			free(*data);
			*data = tmp;
			counter--;
		}
		*data = NULL;
	}
}
