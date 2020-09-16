/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:05:24 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 12:05:27 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char *argv[])
{
	t_lemin		*lemin;
	t_tracks	*tracks;

	lemin = ft_lemin_init();
	if (argc > 1)
		ft_check_flags(lemin, argc, argv);
	lemin = ft_parse_data(lemin);
	//todo убрать тупики и петли!!!
	tracks = ft_find_paths(lemin);
	ft_run_ants_run(lemin, tracks);
	ft_free_lemin(lemin);
	return (0);
}