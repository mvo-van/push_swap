/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:39:48 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/14 17:39:51 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ptr_lst_instr		ft_opti_sa(t_ptr_lst_instr sav)
{
	t_lst	*sup;

	if (sav.sa)
	{
		sav.sa->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.sa;
		sav.sa = sav.sa->prev;
		if (sav.sa)
			sav.sa->next = NULL;
		free(sup);
	}
	else
	{
		sav.pa = ft_free_lst(sav.pa);
		sav.pb = ft_free_lst(sav.pb);
		sav.ra = ft_free_lst(sav.ra);
		sav.rra = ft_free_lst(sav.rra);
		sav.sa = ft_creat(sav.sa, sav.lst);
	}
	return (sav);
}

t_ptr_lst_instr		ft_opti_sb(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.sb)
	{
		sav.sb->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.sb;
		sav.sb = sav.sb->prev;
		if (sav.sb)
			sav.sb->next = NULL;
		free(sup);
	}
	else
	{
		sav.pa = ft_free_lst(sav.pa);
		sav.pb = ft_free_lst(sav.pb);
		sav.rb = ft_free_lst(sav.rb);
		sav.rrb = ft_free_lst(sav.rrb);
		sav.sb = ft_creat(sav.sb, sav.lst);
	}
	return (sav);
}

t_ptr_lst_instr		ft_opti_pa(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.pb)
	{
		sav.pb->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.pb;
		sav.pb = sav.pb->prev;
		if (sav.pb)
			sav.pb->next = NULL;
		free(sup);
	}
	else
	{
		sav.sa = ft_free_lst(sav.sa);
		sav.sb = ft_free_lst(sav.sb);
		sav.ra = ft_free_lst(sav.ra);
		sav.rb = ft_free_lst(sav.rb);
		sav.rra = ft_free_lst(sav.rra);
		sav.rrb = ft_free_lst(sav.rrb);
		sav.pa = ft_creat(sav.pa, sav.lst);
	}
	return (sav);
}

t_ptr_lst_instr		ft_opti_pb(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.pa)
	{
		sav.pa->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.pa;
		sav.pa = sav.pa->prev;
		if (sav.pa)
			sav.pa->next = NULL;
		free(sup);
	}
	else
	{
		sav.sa = ft_free_lst(sav.sa);
		sav.sb = ft_free_lst(sav.sb);
		sav.ra = ft_free_lst(sav.ra);
		sav.rb = ft_free_lst(sav.rb);
		sav.rra = ft_free_lst(sav.rra);
		sav.rrb = ft_free_lst(sav.rrb);
		sav.pb = ft_creat(sav.pb, sav.lst);
	}
	return (sav);
}

t_ptr_lst_instr		ft_opti_ra(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.rra)
	{
		sav.rra->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.rra;
		sav.rra = sav.rra->prev;
		if (sav.rra)
			sav.rra->next = NULL;
		free(sup);
	}
	else
	{
		sav.sa = ft_free_lst(sav.sa);
		sav.pa = ft_free_lst(sav.pa);
		sav.pb = ft_free_lst(sav.pb);
		sav.ra = ft_creat(sav.ra, sav.lst);
	}
	return (sav);
}
