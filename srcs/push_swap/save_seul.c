/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_seul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:44:43 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/12/06 18:45:54 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_ptr_lst	ft_save_b3_seul(t_ptr_lst ptr)
{
	int	o;

	ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
	o = ft_odre(ptr.lst_b->nb, ptr.lst_b->prev->nb, ptr.lst_b->prev->prev->nb);
	if (o == 1 || o == 3)
	{
		if (o == 1)
			ptr = ft_make_instr(ptr, FLAG_SB);
		ptr = ft_make_instr(ptr, FLAG_RRB);
	}
	else if (o == 4)
		ptr = ft_make_instr(ptr, FLAG_SB);
	if (o == 2 || o == 5)
	{
		if (o == 5)
			ptr = ft_make_instr(ptr, FLAG_SB);
		ptr = ft_make_instr(ptr, FLAG_RB);
	}
	ptr = ft_make_instr_times(ptr, FLAG_PA, 3);
	return (ptr);
}

t_ptr_lst	ft_save_b_seul(t_ptr_lst ptr, int cmp)
{
	ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
	if (cmp == 1)
		ptr = ft_make_instr(ptr, FLAG_PA);
	else if (cmp == 2)
	{
		if (ptr.lst_b->nb < ptr.lst_b->prev->nb)
			ptr = ft_make_instr(ptr, FLAG_SB);
		ptr = ft_make_instr_times(ptr, FLAG_PA, 2);
	}
	else if (cmp == 3)
		ptr = ft_save_b3_seul(ptr);
	return (ptr);
}

t_ptr_lst	ft_save_a3_seul(t_ptr_lst ptr)
{
	int	o;

	o = ft_odre(ptr.lst_a->nb, ptr.lst_a->prev->nb, ptr.lst_a->prev->prev->nb);
	if (o == 2 || o == 5)
	{
		if (o == 2)
			ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr(ptr, FLAG_RA);
	}
	else if (o == 3)
		ptr = ft_make_instr(ptr, FLAG_SA);
	if (o == 4 || o == 6)
	{
		if (o == 6)
			ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr(ptr, FLAG_RRA);
	}
	return (ptr);
}

t_ptr_lst	ft_save_a_seul(t_ptr_lst ptr, int cmp)
{
	ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
	if (cmp == 2)
	{
		if (ptr.lst_a->nb > ptr.lst_a->prev->nb)
			ptr = ft_make_instr(ptr, FLAG_SA);
	}
	else if (cmp == 3)
		ptr = ft_save_a3_seul(ptr);
	return (ptr);
}

t_lst_instr	*ft_free_opti(t_lst_instr *lst, t_ptr_lst_instr sav)
{
	sav.sa = ft_free_lst(sav.sa);
	sav.sb = ft_free_lst(sav.sb);
	sav.ra = ft_free_lst(sav.ra);
	sav.rb = ft_free_lst(sav.rb);
	sav.rra = ft_free_lst(sav.rra);
	sav.rrb = ft_free_lst(sav.rrb);
	sav.sa = ft_free_lst(sav.pa);
	sav.sb = ft_free_lst(sav.pb);
	return (lst);
}
