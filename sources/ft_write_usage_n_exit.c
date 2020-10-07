/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_usage_n_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:40:35 by ksemele           #+#    #+#             */
/*   Updated: 2020/10/02 17:40:42 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_write_usage_n_exit(t_lemin *lemin)
{
	ft_putstr(HELP1);
	ft_putstr(HELP2);
	ft_putstr(HELP3);
	ft_putstr(HELP4);
	ft_putstr(HELP5);
	ft_putstr(HELP6);
	ft_putstr(HELP7);
	ft_error_n_exit("", lemin, NULL, NULL);
}
