/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:37:58 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/06/08 10:38:00 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_ptr_list    ft_fusion_gp_droite(t_ptr_list list);

int ft_printf_lst(t_ptr_list list)
{
    t_lst_gp    *lst_a = list.lst_a;
    t_lst_gp    *lst_b = list.lst_b;

    printf("\nAAAAAAAA\n");
    lst_a = ft_lst_next_gp(lst_a);
    lst_b = ft_lst_next_gp(lst_b);
    while (lst_a)
    {
        printf("%d      p%d     g%d\n",lst_a->nb,lst_a->petit,lst_a->grand);
        lst_a = lst_a->prev;
    }
    printf("\nBBBBBBBB\n");
    while (lst_b)
    {
        printf("%d      p%d     g%d\n",lst_b->nb,lst_b->petit,lst_b->grand);
        lst_b = lst_b->prev;
    }    
    return(0);
}


int main(int ac, char **av)
{
    t_ptr_list  list;
    int         i;

    list.lst_a = NULL;
    if(ac == 2)
    {   
        i = 0;
        av = ft_strsplit(av[1],' ');
        while(av[i])
            i++;
        ac = i + 1;
    }
    else if(ac > 2)
        av = av + 1;
    ac--;
    ft_verif_arg(av, ac);
    list.lst_a = ft_creat_lst_gp(av, ac, list.lst_a);
    list = ft_push_swap(list);
    ft_printf_lst(list);
    list.instr = ft_print_instr(list.instr);
    return(0);
}

t_ptr_list    ft_push_swap(t_ptr_list list)
{
    int             nb_gp;
    list.lst_b = NULL;
    list.instr = NULL;
    while ((nb_gp = ft_make_groupe(list.lst_a)) > 1)
    {   
        
        list = ft_divise_gp(list, nb_gp);
        list = ft_goupe_fusion(list);
        nb_gp = ft_make_groupe(list.lst_a);
        if(list.nb_gp > 2)
        {
            list = ft_fusion_gp_droite(list);
            ft_make_groupe_b(list.lst_b);
        }
    }
    list = ft_fusion_gp(list);
    return(list);
}

int     ft_make_groupe(t_lst_gp *lst_a)
{
    int         i;
    t_lst_gp    *ptr;
 
    i = 0;
    ptr = lst_a;
    ptr = ft_lst_prev_gp(ptr);
    if(ptr)
    {
        ft_lst_zero(ptr);
        i++;
        ptr->grand = 1;
        ptr->groupe = i;
        while (ptr && ptr->next)
        {   
            if(ptr->nb > ptr->next->nb)
                ptr->next->groupe = ptr->groupe;
            else
            {
                ptr->next->groupe = ptr->groupe + 1;
                ptr->next->grand = 1;
                ptr->petit = 1;
                i++;
            }
            ptr = ptr->next;
        }
        ptr->petit = 1;
    }   
    return (i);
}

int     ft_make_groupe_b(t_lst_gp *lst_b)
{
    int         i;
    t_lst_gp    *ptr;
 
    i = 0;
    ptr = lst_b;
    ptr = ft_lst_prev_gp(ptr);
    if(ptr)
    {
        ft_lst_zero(ptr);
        i++;
        ptr->petit = 1;
        ptr->groupe = i;
        while (ptr && ptr->next)
        {   
            if(ptr->nb < ptr->next->nb)
                ptr->next->groupe = ptr->groupe;
            else
            {
                ptr->next->groupe = ptr->groupe + 1;
                ptr->next->petit = 1;
                ptr->grand = 1;
                i++;
            }
            ptr = ptr->next;
        }
        ptr->grand = 1;
    }   
    return (i);
}

t_ptr_list    ft_divise_gp(t_ptr_list list, int nb_gp)
{

    int         i;
    int         groupe;

    i = 1;
    list.nb_gp = nb_gp;
    list = ft_goupe_fusion(list);                                           
    if((list.nb_gp < 2))                                                    
        return(list);                                                       
    while(i <= 1)
    {
        list.lst_a = ft_lst_next_gp(list.lst_a);
        groupe = list.lst_a->groupe;
        list = ft_makep_gp(FLAG_PB, list);
        list.instr = ft_creat_instr(FLAG_PB,list.instr);  
        list.lst_a = ft_lst_next_gp(list.lst_a);
        while(list.lst_a && (list.lst_a->groupe == groupe))
        {
            list.lst_a = list.lst_a->prev;
            list = ft_makep_gp(FLAG_PB, list);
            list.instr = ft_creat_instr(FLAG_PB,list.instr);
            list.lst_a = ft_lst_next_gp(list.lst_a);
        }
        i++;
    }
    return(list);
}

t_ptr_list    ft_fusion_gp(t_ptr_list list)
{
    int fin_a;
    int fin_b;

    ft_make_groupe(list.lst_a);
    ft_make_groupe_b(list.lst_b);
    list.lst_b = ft_lst_next_gp(list.lst_b);
    list.lst_a = ft_lst_prev_gp(list.lst_a);
    while (list.lst_b)
    {
        fin_a = 1;
        fin_b = 1;
        while (fin_a || fin_b)
        {
            if(!fin_a)
            {
                while (fin_b)
                {
                    if(list.lst_b->petit)
                        fin_b = 0;
                    list = ft_makep_gp(FLAG_PA, list);
                    list.instr = ft_creat_instr(FLAG_PA, list.instr);
                    list.lst_b = ft_lst_next_gp(list.lst_b);
                }
            }
            else if(!fin_b)
            {
                while (fin_a)
                {
                    //printf("petitttttt   %d\n", list.lst_a->petit);
                    if(list.lst_a->petit)
                        fin_a = 0;
                    ft_makerr_gp(FLAG_RRA, list.lst_a, NULL);
                    list.instr = ft_creat_instr(FLAG_RRA, list.instr);
                    list.lst_a = ft_lst_prev_gp(list.lst_a);
                }
            }
            else
            {
                if(list.lst_a->nb > list.lst_b->nb)
                {
                    if(list.lst_a->petit)
                        fin_a = 0;
                    ft_makerr_gp(FLAG_RRA, list.lst_a, NULL);
                    list.instr = ft_creat_instr(FLAG_RRA, list.instr);
                }
                else
                {
                    if(list.lst_b->petit)
                        fin_b = 0;
                    list = ft_makep_gp(FLAG_PA, list);
                    list.instr = ft_creat_instr(FLAG_PA, list.instr);            
                }        
            }
            list.lst_b = ft_lst_next_gp(list.lst_b);
            list.lst_a = ft_lst_prev_gp(list.lst_a);
        }
    }
    return(list);
}

t_ptr_list    ft_fusion_gp_droite(t_ptr_list list)
{
    int fin_a;
    int fin_b;

    list.lst_a = ft_lst_next_gp(list.lst_a);
    list.lst_b = ft_lst_prev_gp(list.lst_b);
    //while (list.lst_b)
    
    if(list.lst_b)
    {
        fin_a = 1;
        fin_b = 1;
        while (fin_a || fin_b)
        {
            if(!fin_a)
            {
                while (fin_b)
                {
                    if(list.lst_b->grand)
                        fin_b = 0;
                    //printf("RRBBBBBB\n");
                    ft_makerr_gp(FLAG_RRB, NULL, list.lst_b);
                    list.instr = ft_creat_instr(FLAG_RRB, list.instr);
                    list.lst_b = ft_lst_prev_gp(list.lst_b);
                }
            }
            else if(!fin_b)
            {
                while (fin_a)
                {
                    if(list.lst_a->grand)
                        fin_a = 0;
                    list = ft_makep_gp(FLAG_PB, list);
                    list.instr = ft_creat_instr(FLAG_PB, list.instr);
                    list.lst_a = ft_lst_next_gp(list.lst_a);
                }
            }
            else
            {
                if(list.lst_a->nb < list.lst_b->nb)
                {
                    if(list.lst_a->grand)
                        fin_a = 0;
                    list = ft_makep_gp(FLAG_PB, list);
                    list.instr = ft_creat_instr(FLAG_PB, list.instr);
                }
                else
                {
                    if(list.lst_b->grand)
                        fin_b = 0;
                    //printf("RRBBBBBB\n");
                    ft_makerr_gp(FLAG_RRB, NULL, list.lst_b);
                    list.instr = ft_creat_instr(FLAG_RRB, list.instr);                    
                }
            }
            list.lst_a = ft_lst_next_gp(list.lst_a);
            list.lst_b = ft_lst_prev_gp(list.lst_b);
        }
    }
    return(list);
}

t_lst_gp   *ft_creat_lst_gp(char **av,int ac,t_lst_gp *lst_nb)
{
    int         i;
    int         *tab;

    i = 0;
    if (!(tab = (int *)malloc(sizeof (int) * ac)))
        return (NULL);
    while(i < ac)
    {
        tab[i-1] = ft_atoi(av[i]);
        lst_nb = ft_creat_gp(lst_nb, tab[i-1], ac);
        i++;
    }
    free(tab);
    return(lst_nb);
}
