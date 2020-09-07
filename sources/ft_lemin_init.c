/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:09:31 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:09:33 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*ft_lemin_init(void)
{
	t_lemin *tmp;

	tmp = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	if (!tmp)
		ft_error_n_exit(
				"Error malloc in ft_lemin_init()\n",
				NULL,
				NULL,
				NULL);
	tmp->graph = NULL;
	return (tmp);
}
