/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:20:45 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/12/05 16:34:15 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void		ft_reduce_makes(t_lst_gp *lst)
{
	int		tmp;

	while (lst && lst->next && lst->next->next)
		lst = lst->next;
	if (lst && lst->next)
	{
		tmp = lst->nb;
		lst->nb = lst->next->nb;
		lst->next->nb = tmp;
	}
}

void		ft_reduce_maker(t_lst_gp *lst)
{
	t_lst_gp	*save;

	if (lst && lst->next)
	{
		save = lst;
		while (lst && lst->next)
			lst = lst->next;
		lst->prev->next = NULL;
		lst->prev = NULL;
		lst->next = save;
		lst->next->prev = lst;
	}
}

void		ft_reduce_makerr(t_lst_gp *lst)
{
	t_lst_gp	*save;

	if (lst && lst->prev)
	{
		save = lst;
		while (lst && lst->prev)
			lst = lst->prev;
		lst->next->prev = NULL;
		lst->next = NULL;
		lst->prev = save;
		lst->prev->next = lst;
	}
}

t_ptr_list	ft_reduce_makep(int f, t_lst_gp *d, t_lst_gp *r, t_ptr_list l)
{
	t_lst_gp	*save;

	if (d)
	{
		save = d->prev;
		if (d->prev)
			d->prev->next = NULL;
		if (r)
			r->next = d;
		d->prev = r;
		r = d;
		d = save;
	}
	if (f & FLAG_PA)
	{
		l.lst_a = r;
		l.lst_b = d;
	}
	if (f & FLAG_PB)
	{
		l.lst_b = r;
		l.lst_a = d;
	}
	return (l);
}

t_lst_gp	*ft_free_gp(t_lst_gp *lst_b)
{
	t_lst_gp	*save;

	lst_b = ft_lst_prev_gp(lst_b);
	while (lst_b)
	{
		save = lst_b;
		lst_b = lst_b->next;
		if (lst_b)
			lst_b->prev = NULL;
		free(save);
	}
	return (NULL);
}
