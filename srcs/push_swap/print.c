/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:09:35 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/14 16:57:15 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				ft_print_error(int *tab)
{
	if (tab)
		free(tab);
	write(1, "Error\n", 6);
	return (0);
}

void			ft_instr(t_lst_instr *instr)
{
	if (instr->flag & FLAG_RRA)
		write(1, "rra\n", 4);
	else if (instr->flag & FLAG_PA)
		write(1, "pa\n", 3);
	else if (instr->flag & FLAG_PB)
		write(1, "pb\n", 3);
	else if (instr->flag & FLAG_RA)
		write(1, "ra\n", 3);
	else if (instr->flag & FLAG_RB)
		write(1, "rb\n", 3);
	else if (instr->flag & FLAG_SA)
		write(1, "sa\n", 3);
	else if (instr->flag & FLAG_SB)
		write(1, "sb\n", 3);
	else if (instr->flag & FLAG_RRB)
		write(1, "rrb\n", 4);
}

int				ft_free(int sav, char **av, int ac)
{
	int i;

	i = 0;
	if (sav)
	{
		while (i < ac)
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	return (0);
}

int				ft_print_instr(t_ptr_lst ptr, int sav, char **av, int ac)
{
	t_lst_instr	*save;
	t_lst_nb	*s;

	ptr.lst_a = ft_lst_prev_nb(ptr.lst_a);
	ptr.lst_flag = ft_lst_prev_instr(ptr.lst_flag);
	while (ptr.lst_flag)
	{
		save = ptr.lst_flag;
		ft_instr(ptr.lst_flag);
		ptr.lst_flag = ptr.lst_flag->next;
		if (ptr.lst_flag)
			ptr.lst_flag->prev = NULL;
		free(save);
	}
	while (ptr.lst_a)
	{
		s = ptr.lst_a;
		ptr.lst_a = ptr.lst_a->next;
		if (ptr.lst_a)
			ptr.lst_a->prev = NULL;
		free(s);
	}
	free(ptr.deb_tab);
	ptr = ft_t_ptr_lst_zero(NULL);
	return (ft_free(sav, av, ac));
}
