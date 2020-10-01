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

static void	ft_close_files(t_lemin *lemin)
{
	if (lemin->fd_sol > 1)
	{
		free(lemin->solname);
		if (close(lemin->fd_sol))
			write (2, "Error file close\n", 17);
	}
	if (lemin->fd_map)
	{
		if (close(lemin->fd_map))
			write (2, "Error file close\n", 17);
	}
}

int		main(int argc, char *argv[])
{
	t_lemin		*lemin;
	t_tracks	*tracks;

	lemin = ft_lemin_init();
	if (argc > 1)
		ft_check_flags(lemin, argc, argv);
	lemin = ft_parse_data(lemin);
	if (!(tracks = ft_find_paths(lemin)))
	{
		ft_dprintf(lemin->fd_sol, "No solutions!\n");
		ft_close_files(lemin);
		ft_free_lemin(lemin);
		exit(0);
	}
	ft_run_ants_run(lemin, tracks);
	ft_print_steps(lemin);
	ft_close_files(lemin);
	ft_run_visual(lemin);
	ft_free_lemin(lemin);
	ft_free_tracks(tracks);
	return (0);
}