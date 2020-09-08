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

void		ft_check_flags(t_lemin *lemin, int argc, char *argv[])
{
	if (argc != 2 || !ft_strequ(argv[1], "-v"))
		ft_error_n_exit(
				HELP,
				lemin,
				NULL,
				NULL);
	else
		lemin->visual = TRUE;
}
