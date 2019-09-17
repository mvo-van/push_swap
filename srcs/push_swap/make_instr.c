/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:49:46 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/24 17:49:48 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_makeS_gp(int flag,t_lst_gp *lst_a,t_lst_gp *lst_b)
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

t_ptr_list    ft_makeP_gp(int flag,t_ptr_list list)
{
    t_lst_gp   *save;

    list.lst_a = ft_lst_next_gp(list.lst_a);
    list.lst_b = ft_lst_next_gp(list.lst_b);
    if(flag & FLAG_PA)
        if(list.lst_b)
        {
            save = list.lst_b->prev;
            if(list.lst_b->prev)
                list.lst_b->prev->next = NULL;
            if(list.lst_a)
                list.lst_a->next = list.lst_b;
            list.lst_b->prev = list.lst_a;
            list.lst_a = list.lst_b;
            list.lst_b = save;
        }
    if(flag & FLAG_PB)
        if(list.lst_a)
        {
            save = list.lst_a->prev;
            if(list.lst_a->prev)
                list.lst_a->prev->next = NULL;
            if(list.lst_b)
                list.lst_b->next = list.lst_a;
            list.lst_a->prev = list.lst_b;
            list.lst_b = list.lst_a;
            list.lst_a = save;
        }
    return(list);
}

void    ft_makeR_gp(int flag,t_lst_gp *lst_a,t_lst_gp *lst_b)
{
    t_lst_gp    *save;

    lst_a = ft_lst_prev_gp(lst_a);
    lst_b = ft_lst_prev_gp(lst_b);
    if(flag & FLAG_RA)
        if(lst_a && lst_a->next)
        {
            save = lst_a;
            while (lst_a && lst_a->next)
                lst_a = lst_a->next;
            lst_a->prev->next = NULL;
            lst_a->prev = NULL;
            lst_a->next = save;
            lst_a->next->prev = lst_a;
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
            lst_b->next->prev = lst_b;
        }
}


void    ft_makeRR_gp(int flag,t_lst_gp *lst_a,t_lst_gp *lst_b)
{
    t_lst_gp    *save;

    lst_a = ft_lst_next_gp(lst_a);
    lst_b = ft_lst_next_gp(lst_b);
    if(flag & FLAG_RRA)
        if(lst_a && lst_a->prev)
        {
            save = lst_a;
            while (lst_a && lst_a->prev)
                lst_a = lst_a->prev;
            lst_a->next->prev = NULL;
            lst_a->next = NULL;
            lst_a->prev = save;
            lst_a->prev->next = lst_a;
        }
    if(flag & FLAG_RRB)
        if(lst_a && lst_b->prev)
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

int     ft_verif_arg(char **av, int ac)
{
    int     i;
    int     j;

    i = 1;
    while(i < ac)
    {   
        j = 0;
        if(av[i][j] == '-')
            j++;
        while(av[i][j])
        {
            if(av[i][j] < '0' || av[i][j] > '9')
                return (0);
            j++;   
        }
        i++;
    }
    return(1);
}
