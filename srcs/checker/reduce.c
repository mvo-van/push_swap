/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:35:42 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/06/08 11:35:51 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_ptr_list	ft_reduce_p(int flag, t_lst_gp *ls_d, t_lst_gp *ls_r, t_ptr_list pt)
{
	t_lst_gp	*save;

	if (ls_d)
	{
		save = ls_d->prev;
		if (ls_d->prev)
			ls_d->prev->next = NULL;
		if (ls_r)
			ls_r->next = ls_d;
		ls_d->prev = ls_r;
		ls_r = ls_d;
		ls_d = save;
	}
	if (flag & FLAG_PA)
	{
		pt.lst_a = ls_r;
		pt.lst_b = ls_d;
	}
	if (flag & FLAG_PB)
	{
		pt.lst_b = ls_r;
		pt.lst_a = ls_d;
	}
	return (pt);
}

int			ft_atoi_verif_arg(const char *str)
{
	long	i;
	long	s;
	long	nb;
	int		ret;

	nb = 0;
	i = 0;
	s = 1;
	ret = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if ((nb * s) > INT_MAX || (nb * s) < INT_MIN)
		ret = 0;
	return (ret);
}
