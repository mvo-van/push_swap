/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:24:55 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/12/05 16:47:58 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void		ft_makes_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b)
{
	lst_a = ft_lst_prev_gp(lst_a);
	lst_b = ft_lst_prev_gp(lst_b);
	if (flag & FLAG_SA)
		ft_reduce_makes(lst_a);
	if (flag & FLAG_SB)
		ft_reduce_makes(lst_b);
}

t_ptr_list	ft_makep_gp(int flag, t_ptr_list list)
{
	list.lst_a = ft_lst_next_gp(list.lst_a);
	list.lst_b = ft_lst_next_gp(list.lst_b);
	if (flag & FLAG_PA)
		list = ft_reduce_makep(FLAG_PA, list.lst_b, list.lst_a, list);
	if (flag & FLAG_PB)
		list = ft_reduce_makep(FLAG_PB, list.lst_a, list.lst_b, list);
	return (list);
}

void		ft_maker_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b)
{
	lst_a = ft_lst_prev_gp(lst_a);
	lst_b = ft_lst_prev_gp(lst_b);
	if (flag & FLAG_RA)
		ft_reduce_maker(lst_a);
	if (flag & FLAG_RB)
		ft_reduce_maker(lst_b);
}

void		ft_makerr_gp(int flag, t_lst_gp *lst_a, t_lst_gp *lst_b)
{
	lst_a = ft_lst_next_gp(lst_a);
	lst_b = ft_lst_next_gp(lst_b);
	if (flag & FLAG_RRA)
		ft_reduce_makerr(lst_a);
	if (flag & FLAG_RRB)
		ft_reduce_makerr(lst_b);
}

int			ft_verif_arg(int *tab, int x, char *str)
{
	long	i;
	long	s;
	long	nb;

	nb = 0;
	i = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if ((nb * s < -2147483648) || (nb * s > 2147483647))
			return (0);
		i++;
	}
	while (--x > 0)
		if (x > 0 && nb * s == tab[x - 1])
			return (0);
	return (1);
}
