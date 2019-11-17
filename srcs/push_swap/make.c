/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:09:19 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/14 18:06:25 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ptr_lst	ft_make_p_nb(int flag, t_ptr_lst list)
{
	t_lst_nb	*save;

	if (flag & FLAG_PA && list.lst_b)
	{
		save = list.lst_b->prev;
		if (list.lst_b->prev)
			list.lst_b->prev->next = NULL;
		if (list.lst_a)
			list.lst_a->next = list.lst_b;
		list.lst_b->prev = list.lst_a;
		list.lst_a = list.lst_b;
		list.lst_b = save;
	}
	if (flag & FLAG_PB && list.lst_a)
	{
		save = list.lst_a->prev;
		if (list.lst_a->prev)
			list.lst_a->prev->next = NULL;
		if (list.lst_b)
			list.lst_b->next = list.lst_a;
		list.lst_a->prev = list.lst_b;
		list.lst_b = list.lst_a;
		list.lst_a = save;
	}
	return (list);
}

void		ft_make_s_nb(int flag, t_lst_nb *lst_a, t_lst_nb *lst_b)
{
	lst_a = ft_lst_next_nb(lst_a);
	lst_b = ft_lst_next_nb(lst_b);
	if (flag & FLAG_SA)
		if (lst_a && lst_a->prev)
		{
			if (lst_a->prev->prev)
				lst_a->prev->prev->next = lst_a;
			lst_a->prev->next = NULL;
			lst_a->next = lst_a->prev;
			lst_a->prev = lst_a->prev->prev;
			lst_a->next->prev = lst_a;
		}
	if (flag & FLAG_SB)
		if (lst_b && lst_b->prev)
		{
			if (lst_b->prev->prev)
				lst_b->prev->prev->next = lst_b;
			lst_b->prev->next = NULL;
			lst_b->next = lst_b->prev;
			lst_b->prev = lst_b->prev->prev;
			lst_b->next->prev = lst_b;
		}
}

void		ft_make_r_nb(int flag, t_lst_nb *lst_a, t_lst_nb *lst_b)
{
	t_lst_nb	*save;

	lst_a = ft_lst_prev_nb(lst_a);
	lst_b = ft_lst_prev_nb(lst_b);
	if (flag & FLAG_RA && lst_a && lst_a->next)
	{
		save = lst_a;
		while (lst_a && lst_a->next)
			lst_a = lst_a->next;
		lst_a->prev->next = NULL;
		lst_a->prev = NULL;
		lst_a->next = save;
		lst_a->next->prev = lst_a;
	}
	if (flag & FLAG_RB && lst_b && lst_b->next)
	{
		save = lst_b;
		while (lst_b && lst_b->next)
			lst_b = lst_b->next;
		lst_b->prev->next = NULL;
		lst_b->prev = NULL;
		lst_b->next = save;
		lst_b->next->prev = lst_b;
	}
}

void		ft_make_rr_nb(int flag, t_lst_nb *lst_a, t_lst_nb *lst_b)
{
	t_lst_nb	*save;

	lst_a = ft_lst_next_nb(lst_a);
	lst_b = ft_lst_next_nb(lst_b);
	if (flag & FLAG_RRA && lst_a && lst_a->prev)
	{
		save = lst_a;
		while (lst_a && lst_a->prev)
			lst_a = lst_a->prev;
		lst_a->next->prev = NULL;
		lst_a->next = NULL;
		lst_a->prev = save;
		lst_a->prev->next = lst_a;
	}
	if (flag & FLAG_RRB && lst_b && lst_b->prev)
	{
		save = lst_b;
		while (lst_b && lst_b->prev)
			lst_b = lst_b->prev;
		lst_b->next->prev = NULL;
		lst_b->next = NULL;
		lst_b->prev = save;
		lst_b->prev->next = lst_b;
	}
}
