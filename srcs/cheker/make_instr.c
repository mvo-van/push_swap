/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:24:55 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/07 17:24:57 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

void    ft_makeS(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b)
{
    int    tmp;

    if(flag & FLAG_SA)
    {
        while(lst_a && lst_a->next && lst_a->next->next)
            lst_a = lst_a->next;
        if(lst_a && lst_a->next)
        {
            tmp = lst_a->nb;
            lst_a->nb = lst_a->next->nb;
            lst_a->next->nb = tmp;
        }
    }
    if(flag & FLAG_SB)
    {
        while(lst_b && lst_b->next && lst_b->next->next)
            lst_b = lst_b->next;
        if(lst_b && lst_b->next)
        {
            tmp = lst_b->nb;
            lst_b->nb = lst_b->next->nb;
            lst_b->next->nb = tmp;
        }
    }   
}
void    ft_makeP(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b)
{
    t_lst_nb   *save;
    
    lst_a = ft_lst_next(lst_a);
    lst_b = ft_lst_next(lst_b);
    if(flag & FLAG_PA)
        if(lst_b)
        {
            save = lst_b->prev;
            if(lst_b->prev)
                lst_b->prev->next = NULL;
            lst_a->next = lst_b;
            lst_b->prev = lst_a;
            lst_b = save;
        }
    if(flag & FLAG_PB)
        if(lst_a)
        {
            save = lst_a->prev;
            if(lst_a->prev)
                lst_a->prev->next = NULL;
            lst_b->next = lst_a;
            lst_a->prev = lst_b;
            lst_a = save;
        }
}
void    ft_makeR(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b)
{
    t_lst_nb    *save;

    lst_a = ft_lst_prev(lst_a);
    lst_b = ft_lst_prev(lst_b);
    if(flag & FLAG_RA)
        if(lst_a && lst_a->next)
        {
            save = lst_a;
            while (lst_a && lst_a->next)
                lst_a = lst_a->next;
            lst_a->prev->next = NULL;
            lst_a->prev = NULL;
            lst_a->next = save;
            lst_a->prev->next = lst_a;
        }
    if(flag & FLAG_RB)
        if(lst_b && lst_b->next)
        {
            save = lst_b;
            while (lst_b && lst_b->next)
                lst_b = lst_b->next;
            lst_b->prev->next = NULL;
            lst_b->prev = NULL;
            lst_b->next = save;
            lst_b->prev->next = lst_b;
        }
}
void    ft_makeRR(int flag,t_lst_nb *lst_a,t_lst_nb *lst_b)
{
    t_lst_nb    *save;

    lst_a = ft_lst_next(lst_a);
    lst_b = ft_lst_next(lst_b);
    if(flag & FLAG_RRA)
        if(lst_a && lst_a->prev)
        {
            save = lst_a;
            while (lst_a && lst_a->prev)
                lst_a = lst_a->prev;
            lst_a->next->prev = NULL;
            lst_a->next = NULL;
            lst_a->prev = save;
            lst_a->next->prev = lst_a;
        }
    if(flag & FLAG_RRB)
        if(lst_b && lst_b->prev)
        {
            save = lst_b;
            while (lst_b && lst_b->prev)
                lst_b = lst_b->prev;
            lst_b->next->prev = NULL;
            lst_b->next = NULL;
            lst_b->prev = save;
            lst_b->next->prev = lst_b;
        }
}
//void    ft_lst_size(t_lst_nb lst_a, t_lst_nb lst_b, int size_a, int size_b)
