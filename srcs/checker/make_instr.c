/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:35:23 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/06/08 10:55:06 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_makes_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b)
{
	lst_a = ft_lst_prev_gp(lst_a);
	lst_b = ft_lst_prev_gp(lst_b);
	if (flag & FLAG_SA)
		ft_reduce_makes(lst_a);
	if (flag & FLAG_SB)
		ft_reduce_makes(lst_b);
}

t_ptr_list		ft_makep_gp(int flag, t_ptr_list list)
{
	list.lst_a = ft_lst_next_gp(list.lst_a);
	list.lst_b = ft_lst_next_gp(list.lst_b);
	if (flag & FLAG_PA)
		list = ft_reduce_p(FLAG_PA, list.lst_b, list.lst_a, list);
	if (flag & FLAG_PB)
		list = ft_reduce_p(FLAG_PB, list.lst_a, list.lst_b, list);
	return (list);
}

void			ft_maker_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b)
{
	lst_a = ft_lst_prev_gp(lst_a);
	lst_b = ft_lst_prev_gp(lst_b);
	if (flag & FLAG_RA)
		ft_reduce_maker(lst_a);
	if (flag & FLAG_RB)
		ft_reduce_maker(lst_b);
}

void			ft_makerr_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b)
{
	lst_a = ft_lst_next_gp(lst_a);
	lst_b = ft_lst_next_gp(lst_b);
	if (flag & FLAG_RRA)
		ft_reduce_makerr(lst_a);
	if (flag & FLAG_RRB)
		ft_reduce_makerr(lst_b);
}

void			ft_verif_arg(char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i] && !(ft_atoi_verif_arg(av[i])))
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (av[i][j] && (av[i][j] == '-' || av[i][j] == '+'))
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
