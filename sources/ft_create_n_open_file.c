/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_n_open_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:32:15 by ksemele           #+#    #+#             */
/*   Updated: 2020/10/02 17:52:42 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_create_n_open_file(t_lemin *lemin, char *file, int *fd)
{
	if (*fd > 1)
		close(*fd);
	*fd = open(file, O_RDWR | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE);
	if (*fd < 0)
		ft_error_n_exit("Error open file\n", lemin, NULL, NULL);
}
