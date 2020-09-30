//
// Created by  Anton Gorobets on 30.09.2020.
//

#include "lemin.h"

void			ft_print_steps(t_lemin *lemin)
{
	t_print	*tmp_pr;
	t_step	*tmp_st;

	tmp_pr = lemin->print;
	while (tmp_pr)
	{
		tmp_st = tmp_pr->step;
		while (tmp_st)
		{
			ft_printf("L%d-%s", tmp_st->ant, lemin->graph[tmp_st->room].name);
			tmp_st = tmp_st->next;
			if (tmp_st)
				ft_printf(" ");
		}
		ft_printf("\n");
		tmp_pr = tmp_pr->next;
	}
}
