//
// Created by  Anton Gorobets on 01.10.2020.
//

#include "lemin.h"

void		ft_write_usage_n_exit(t_lemin *lemin)
{
	write (1, HELP1, ft_strlen(HELP1));
	write (1, HELP2, ft_strlen(HELP2));
	write (1, HELP3, ft_strlen(HELP3));
	write (1, HELP4, ft_strlen(HELP4));
	ft_error_n_exit("", lemin, NULL, NULL);
}
