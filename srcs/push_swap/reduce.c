/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:38:08 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/06/08 10:38:11 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_reduce_makes(t_lst_gp *lst)
{
    int    tmp;

    while(lst && lst->next && lst->next->next)
        lst = lst->next;
    if(lst && lst->next)
    { 
        tmp = lst->nb;
        lst->nb = lst->next->nb;
        lst->next->nb = tmp;
    }
}

void    ft_reduce_maker(t_lst_gp *lst)
{
    t_lst_gp    *save;

    if(lst && lst->next)
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

void    ft_reduce_makerr(t_lst_gp *lst)
{
    t_lst_gp    *save;

    if(lst && lst->prev)
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

t_ptr_list    ft_reduce_p(int flag, t_lst_gp *lst_don, t_lst_gp *lst_rec, t_ptr_list list)
{
    t_lst_gp   *save;

    if(lst_don)
    {
        save = lst_don->prev;
        if(lst_don->prev)
            lst_don->prev->next = NULL;
        if(lst_rec)
            lst_rec->next = lst_don;
        lst_don->prev = lst_rec;
        lst_rec = lst_don;
        lst_don = save;
    }
    if(flag & FLAG_PA)
    {
        list.lst_a = lst_rec;
        list.lst_b = lst_don;
    }
    if(flag & FLAG_PB)
    {
        list.lst_b = lst_rec;
        list.lst_a = lst_don;
    }
    return (list);
}

int		ft_atoi_verif_arg(const char *str)
{
	long	i;
	long	s;
	long	nb;
    int     ret;

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
    if((nb * s) > INT_MAX || (nb * s) < INT_MIN)
        ret = 0;
	return (ret);
}
