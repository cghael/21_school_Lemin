/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_n_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:16:06 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:16:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_error_n_exit(char *str, t_lemin *lemin, t_data **data)
{
	write(2, str, ft_strlen(str));
	if (data)
		ft_free_data(data);
	if (lemin)
		ft_free_lemin(lemin);
	exit(EXIT_FAILURE);
}
