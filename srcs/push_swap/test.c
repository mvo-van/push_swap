/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:10:14 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/14 17:16:03 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ptr_lst		ft_divise_avb(t_ptr_lst ptr, int *tab)
{
	int		cmp;
	int		piv;
	int		nb_ra;

	nb_ra = 0;
	cmp = ft_cmp_gp(ptr.lst_a) + 1;
	piv = tab[cmp / 2];
	while (--cmp > 0)
	{
		ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
		if (ptr.lst_a->nb < piv)
		{
			ptr.lst_a->gp++;
			ptr = ft_make_instr(ptr, FLAG_PB);
		}
		else
		{
			ptr = ft_make_instr(ptr, FLAG_RA);
			nb_ra++;
		}
	}
	nb_ra++;
	while (--nb_ra > 0 && ft_cmp_lst_gp(ptr.lst_a))
		ptr = ft_make_instr(ptr, FLAG_RRA);
	return (ptr);
}

t_ptr_lst		ft_divise_bva(t_ptr_lst ptr, int *tab)
{
	int		cmp;
	int		piv;

	cmp = ft_cmp_gp(ptr.lst_b);
	piv = tab[cmp / 2];
	while (cmp > 0)
	{
		ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
		if (ptr.lst_b->nb >= piv)
			ptr = ft_make_instr(ptr, FLAG_PA);
		else
		{
			ptr.lst_b->gp++;
			ptr = ft_make_instr(ptr, FLAG_RB);
		}
		cmp--;
	}
	return (ptr);
}

t_ptr_lst		ft_push_swap(t_ptr_lst ptr)
{
	int		cmp;

	if ((cmp = ft_cmp_gp(ptr.lst_a)) > 3)
	{
		ptr = ft_divise_avb(ptr, ptr.tab);
		while ((cmp = ft_cmp_gp(ptr.lst_b)) > 3)
			ptr = ft_divise_bva(ptr, ptr.tab);
		ptr = ft_save_b(ptr, cmp);
		ptr.tab += cmp;
	}
	else
	{
		ptr = ft_save_a(ptr, cmp);
		ptr.tab += cmp;
	}
	return (ptr);
}

void			ft_gp_zero(t_lst_nb *lst, int i)
{
	lst = ft_lst_next_nb(lst);
	while (lst && i > 0)
	{
		lst->gp = 0;
		lst = lst->prev;
		i--;
	}
}

t_ptr_lst		ft_make_instr_times(t_ptr_lst ptr, int flag, int times)
{
	while (times > 0)
	{
		ptr = ft_make_instr(ptr, flag);
		times--;
	}
	return (ptr);
}
