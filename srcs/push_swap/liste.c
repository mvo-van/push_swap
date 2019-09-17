/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:48:48 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/24 17:48:58 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
t_lst_gp    *ft_creat_gp(t_lst_gp *lst_nb, int i, int size)
{
    t_lst_gp    *new;

    if ((new = (t_lst_gp *)malloc(sizeof(t_lst_gp) * 1)))
    {
        if (lst_nb)
            lst_nb->prev = new;
        new->groupe = 0;
        new->piv = 0;
        new->petit = 0;
        new->grand = 0;
        new->next = lst_nb;
        new->nb = i;
        new->size = size;
        new->prev = NULL;
    }
    return (new);
}

t_lst_instr    *ft_creat_instr(int  flag, t_lst_instr *lst_instr)
{
    t_lst_instr    *new;
    //printf("fdhjkhdfkjhfkjhd\n");
    if ((new = (t_lst_instr *)malloc(sizeof(t_lst_instr) * 1)))
    {
        if (lst_instr)
            lst_instr->next = new;
        new->flag = flag; 
        new->prev = lst_instr;
        new->next = NULL;
    }
    return (new);
}

t_lst_gp    *ft_lst_prev_gp(t_lst_gp *ptr)
{
    while(ptr && ptr->prev)
        ptr = ptr->prev;
    return(ptr);
}

t_lst_gp    *ft_lst_next_gp(t_lst_gp *ptr)
{
    while(ptr && ptr->next)
        ptr = ptr->next;
    return(ptr);
}

void    ft_lst_zero(t_lst_gp *lst_a)
{
    t_lst_gp    *ptr;

    ptr = lst_a;
    ptr = ft_lst_prev_gp(ptr);
    while(ptr)
    {
        ptr->petit = 0;
        ptr->grand = 0;
        ptr->groupe = 0;
        ptr = ptr->next;
    }
}
