/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:27:28 by cghael            #+#    #+#             */
/*   Updated: 2020/08/25 13:27:30 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_check_f_flag(t_lemin *lemin, char *file, int *i)
{
	int		j;
	char	*dot;

	j = 0;
	while (file[j])
	{
		if (!ft_isalnum(file[j]))
		{
			if (!(dot = ft_strchr(file, '.')) \
			|| !ft_strequ(dot + 1, "sol"))
				ft_write_usage_n_exit(lemin);
		}
		j++;
	}
	ft_create_n_open_file(lemin, file, &lemin->fd_sol);
	if (!(lemin->solname = ft_strdup(file)))
		ft_error_n_exit("Error in ft_check_f_flag\n", lemin, NULL, NULL);
	*i = *i + 1;
}

static void	ft_open_file(t_lemin *lemin, char *file, int *fd)
{
	if (*fd > 1)
		close(*fd);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		ft_error_n_exit("Error open file\n", lemin, NULL, NULL);
}

static void	ft_check_o_flag(t_lemin *lemin, char *file, int *i)
{
	int		j;
	char	*dot;

	j = 0;
	while (file[j])
	{
		if (!ft_isalnum(file[j]))
		{
			if (!(dot = ft_strchr(file, '.')) \
			|| !ft_strequ(dot + 1, "map"))
				ft_write_usage_n_exit(lemin);
		}
		j++;
	}
	ft_open_file(lemin, file, &lemin->fd_map);
	*i = *i + 1;
}

static void	ft_check_ow_flag(t_lemin *lemin, char *file, int *i)
{
	int		j;
	char	*dot;
	char	*sol_name;

	j = 0;
	while (file[j])
	{
		if (!ft_isalnum(file[j]))
		{
			if (!(dot = ft_strchr(file, '.')) \
			|| !ft_strequ(dot + 1, "map"))
				ft_write_usage_n_exit(lemin);
		}
		j++;
	}
	ft_open_file(lemin, file, &lemin->fd_map);
	if (!(sol_name = ft_strsub(file, 0, dot - file + 1)))
		ft_error_n_exit("Error in ft_check_ow_flag\n", lemin, NULL, NULL);
	if (!(lemin->solname = ft_strjoin(sol_name, "sol")))
	{
		free(sol_name);
		ft_error_n_exit("Error in ft_check_ow_flag\n", lemin, NULL, NULL);
	}
	free(sol_name);
	ft_create_n_open_file(lemin, lemin->solname, &lemin->fd_sol);
	*i = *i + 1;
}

void		ft_check_flags(t_lemin *lemin, int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-f") && (i + 1 < argc))
			ft_check_f_flag(lemin, argv[i + 1], &i);
		else if (ft_strequ(argv[i], "-v"))
		{
			ft_create_n_open_file(lemin, "viz.sol", &lemin->fd_sol);
			lemin->solname = ft_strdup("viz.sol");
			lemin->visual = TRUE;
		}
		else if (ft_strequ(argv[i], "-o") && (i + 1 < argc))
			ft_check_o_flag(lemin, argv[i + 1], &i);
		else if (ft_strequ(argv[1], "-of") && (i + 1 < argc))
			ft_check_ow_flag(lemin, argv[i + 1], &i);
		else if (ft_strequ(argv[1], "-no"))
			ft_you_were_warned(lemin);
		else if (i == 1 && argc == 2)
			ft_check_o_flag(lemin, argv[i], &i);
		else
			ft_write_usage_n_exit(lemin);
		i++;
	}
}
