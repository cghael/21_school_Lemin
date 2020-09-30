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

static int	ft_check_filename(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void		ft_check_flags(t_lemin *lemin, int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-f"))
		{
			ft_check_f_flag(lemin, argv[i], argv[i + 1]);

			i++;
		}
		else if (ft_strequ(argv[1], "-v"))
			ft_check_v_flag();
		else if (ft_strequ(argv[1], "-o"))
		{
			ft_check_o_flag();
			i++;
		}
		else if (ft_strequ(argv[1], "--w"))
			ft_check_w_flag();
		i++;
	}




	if (ft_strequ(argv[1], "-f"))
	{
		if (argc < 2 || EXIT_FAILURE == ft_check_filename(argv[2]))
			ft_error_n_exit(USAGE_FILE, lemin, NULL, NULL);
		lemin->fd = open("./", O_CREAT, O_RDWR);
		if (lemin->fd < 0)
			ft_error_n_exit("Error open file\n", lemin, NULL, NULL);
	}
	else if (ft_strequ(argv[1], "-v"))
	{
		lemin->visual = TRUE;
//		lemin->fd =
		//todo visual
	}
	else
	{
		write (2, HELP1, ft_strlen(HELP1));
		write (2, HELP2, ft_strlen(HELP2));
		ft_error_n_exit("", lemin, NULL, NULL);
	}
}
