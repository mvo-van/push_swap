/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:24:41 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/07 17:24:45 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"
        #include <stdio.h>
t_lst_nb    *ft_creat_nb(t_lst_nb *lst_nb, int i, int size)
{
    t_lst_nb    *new;
    
    if ((new = (t_lst_nb *)malloc(sizeof(t_lst_nb) * 1)))
    {
        if (lst_nb)
            lst_nb->prev = new;
        new->next = lst_nb;
        new->nb = i;
        new->size = size;
        new->prev = NULL;
    }
    return (new);
}

t_lst_instr    *ft_creat_instr(t_save  save, t_lst_instr *lst_instr)
{
    t_lst_instr    *new;

    if ((new = (t_lst_instr *)malloc(sizeof(t_lst_instr) * 1)))
    {
        if (lst_instr)
            lst_instr->next = new;
        new->flag = 0; 
        new->prev = lst_instr;
        if (ft_strlen(save.str) == 2)
        {
            if (save.str[0] == 's')
                ft_verifS(save.str[1], new);
            else if (save.str[0] == 'p')
                ft_verifP(save.str[1], new);
            else if (save.str[0] == 'r')
                ft_verifR(save.str[1], new);
        }
        else if (save.str[0] == 'r' && save.str[1] == 'r')
            ft_verifRR(save.str[2], new);
        new->next = NULL;
    }
    return (new);
}

t_lst_nb    *ft_lst_prev(t_lst_nb *ptr)
{
    while(ptr && ptr->prev)
        ptr = ptr->prev;
    return (ptr);
}

t_lst_nb    *ft_lst_next(t_lst_nb *ptr)
{
    while(ptr && ptr->next)
        ptr = ptr->next;
    return (ptr);
}