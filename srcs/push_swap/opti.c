/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:29:26 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/12/05 18:18:31 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_ptr_lst_instr		ft_opti_rb(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.rrb)
	{
		sav.rrb->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.rrb;
		sav.rrb = sav.rrb->prev;
		if (sav.rrb)
			sav.rrb->next = NULL;
		free(sup);
	}
	else
	{
		sav.sb = ft_free_lst(sav.sb);
		sav.pa = ft_free_lst(sav.pa);
		sav.pb = ft_free_lst(sav.pb);
		sav.rb = ft_creat(sav.rb, sav.lst);
	}
	return (sav);
}

t_ptr_lst_instr		ft_opti_rra(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.ra)
	{
		sav.ra->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.ra;
		sav.ra = sav.ra->prev;
		if (sav.ra)
			sav.ra->next = NULL;
		free(sup);
	}
	else
	{
		sav.sa = ft_free_lst(sav.sa);
		sav.pa = ft_free_lst(sav.pa);
		sav.pb = ft_free_lst(sav.pb);
		sav.rra = ft_creat(sav.rra, sav.lst);
	}
	return (sav);
}

t_ptr_lst_instr		ft_opti_rrb(t_ptr_lst_instr sav)
{
	t_lst *sup;

	if (sav.rb)
	{
		sav.rb->ptr->flag = 0;
		sav.lst->flag = 0;
		sup = sav.rb;
		sav.rb = sav.rb->prev;
		if (sav.rb)
			sav.rb->next = NULL;
		free(sup);
	}
	else
	{
		sav.sb = ft_free_lst(sav.sb);
		sav.pa = ft_free_lst(sav.pa);
		sav.pb = ft_free_lst(sav.pb);
		sav.rrb = ft_creat(sav.rrb, sav.lst);
	}
	return (sav);
}

t_lst_instr			*ft_opti_instr(t_lst_instr *lst)
{
	t_ptr_lst_instr sav;

	sav = ft_sav_zero(lst);
	sav.lst = ft_lst_prev_instr(sav.lst);
	while (sav.lst)
	{
		if (sav.lst->flag & FLAG_SA)
			sav = ft_opti_sa(sav);
		else if (sav.lst->flag & FLAG_SB)
			sav = ft_opti_sb(sav);
		else if (sav.lst->flag & FLAG_PA)
			sav = ft_opti_pa(sav);
		else if (sav.lst->flag & FLAG_PB)
			sav = ft_opti_pb(sav);
		else if (sav.lst->flag & FLAG_RA)
			sav = ft_opti_ra(sav);
		else if (sav.lst->flag & FLAG_RB)
			sav = ft_opti_rb(sav);
		else if (sav.lst->flag & FLAG_RRA)
			sav = ft_opti_rra(sav);
		else if (sav.lst->flag & FLAG_RRB)
			sav = ft_opti_rrb(sav);
		sav.lst = sav.lst->next;
	}
	return (ft_free_opti(lst, sav));
}

t_ptr_lst_instr		ft_sav_zero(t_lst_instr *lst)
{
	t_ptr_lst_instr sav;

	sav.sa = NULL;
	sav.sb = NULL;
	sav.pa = NULL;
	sav.pb = NULL;
	sav.ra = NULL;
	sav.rb = NULL;
	sav.rra = NULL;
	sav.rrb = NULL;
	sav.lst = lst;
	return (sav);
}
