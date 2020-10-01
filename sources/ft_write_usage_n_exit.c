//
// Created by  Anton Gorobets on 01.10.2020.
//

#include "lemin.h"

void		ft_write_usage_n_exit(t_lemin *lemin)
{
	ft_putstr(HELP1);
	ft_putstr(HELP2);
	ft_putstr(HELP3);
	ft_putstr(HELP4);
	ft_putstr(HELP5);
	ft_putstr(HELP6);
	ft_error_n_exit("", lemin, NULL, NULL);
}
