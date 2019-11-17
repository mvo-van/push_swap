/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:23:48 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/15 17:44:08 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ptr_lst	ft_save_a32(t_ptr_lst ptr, int o)
{
	if (o == 2)
	{
		ptr = ft_make_instr(ptr, FLAG_RA);
		ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr_times(ptr, FLAG_RA, 2);
	}
	else if (o == 4)
	{
		ptr = ft_make_instr(ptr, FLAG_PB);
		ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr(ptr, FLAG_RA);
		ptr = ft_make_instr(ptr, FLAG_PA);
		ptr = ft_make_instr_times(ptr, FLAG_RA, 2);
	}
	else
	{
		ptr = ft_make_instr(ptr, FLAG_PB);
		if (o == 6)
			ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr_times(ptr, FLAG_RA, 2);
		ptr = ft_make_instr(ptr, FLAG_PA);
		ptr = ft_make_instr(ptr, FLAG_RA);
	}
	return (ptr);
}

t_ptr_lst	ft_save_a3(t_ptr_lst ptr)
{
	int	o;

	ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
	o = ft_odre(ptr.lst_a->nb, ptr.lst_a->prev->nb, ptr.lst_a->prev->prev->nb);
	if (o == 1 || o == 3)
	{
		if (o == 3)
			ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr_times(ptr, FLAG_RA, 3);
	}
	else
		ptr = ft_save_a32(ptr, o);
	return (ptr);
}

t_ptr_lst	ft_save_a(t_ptr_lst ptr, int cmp)
{
	ft_gp_zero(ptr.lst_a, cmp);
	if (ft_cmp_lst_nb(ptr.lst_a) <= 3)
		ptr = ft_save_a_seul(ptr, cmp);
	else if (cmp == 1)
		ptr = ft_make_instr(ptr, FLAG_RA);
	else if (cmp == 2)
	{
		ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
		if (ptr.lst_a->nb > ptr.lst_a->prev->nb)
			ptr = ft_make_instr(ptr, FLAG_SA);
		ptr = ft_make_instr_times(ptr, FLAG_RA, 2);
	}
	else if (cmp == 3)
		ptr = ft_save_a3(ptr);
	return (ptr);
}

t_ptr_lst	ft_save_b3(t_ptr_lst ptr)
{
	int	o;

	ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
	o = ft_odre(ptr.lst_b->nb, ptr.lst_b->prev->nb, ptr.lst_b->prev->prev->nb);
	if (o == 1 || o == 3)
		ptr = ft_make_instr(ptr, FLAG_RRB);
	else if (o == 2)
		ptr = ft_make_instr(ptr, FLAG_RB);
	ptr = ft_make_instr_times(ptr, FLAG_PA, 3);
	return (ptr);
}

t_ptr_lst	ft_save_b(t_ptr_lst ptr, int cmp)
{
	if (ft_cmp_lst_nb(ptr.lst_b) <= 3)
		ptr = ft_save_b_seul(ptr, cmp);
	else if (cmp == 1)
		ptr = ft_make_instr(ptr, FLAG_PA);
	else if (cmp == 2)
		ptr = ft_make_instr_times(ptr, FLAG_PA, 2);
	else if (cmp == 3)
		ptr = ft_save_b3(ptr);
	ptr = ft_save_a(ptr, cmp);
	return (ptr);
}
