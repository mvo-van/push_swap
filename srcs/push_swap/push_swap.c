/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:49:33 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/24 17:49:36 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int         *tab;
    t_ptr_list  list;
    int         i;

    i = 1;
    list.lst_a = NULL;

    if(!(tab = (int *)malloc(sizeof (int) * ac - 1)))
        return (0);  
    if(!ft_verif_arg(av, ac))
    {
        write(1, "Error\n", 6);
        return(0);
    }
    while(i < ac)
    {
        tab[i-1] = ft_atoi(av[i]);
        list.lst_a = ft_creat_gp(list.lst_a, tab[i-1], ac - 1);
        i++;
    }
    list = ft_push_swap(list);
    list.instr = ft_print_instr(list.instr);

list.lst_a = ft_lst_next_gp(list.lst_a);
/*
while (list.lst_a)
{
printf("%d \n",list.lst_a->nb);
list.lst_a = list.lst_a->prev;
}*/
  
       
    return(0);
}

t_ptr_list    ft_push_swap(t_ptr_list list)
{
    int             nb_gp;

    list.lst_b = NULL;
    list.instr = NULL;
    while ((nb_gp = ft_make_groupe(list.lst_a)) > 1)
    {   
        //printf("%d\n",nb_gp);
        list = ft_divise_gp(list, nb_gp);
        list = ft_fusion_gp(list);
    }
int i;                                                                      ///////////////////
i=0;  /*                                                                          ////////////////////////////////////
    while (list.instr)                                                                  //////////////////////////////
    {                                                                       /////////////////////////////////////
        i++;                                                            /////////////////////////////////////////////
            printf("%d \n",list.instr->flag);                                           ///////////////////////
            list.instr = list.instr->prev;                                              //////////////////////////
    }                                                                                               //////////////////////
    printf("\n\n iiiiiiii %d \n\n",i);*/                                                  /////////////////////////////////
    return(list);
}

int     ft_make_groupe(t_lst_gp *lst_a)
{
    int         i;
    t_lst_gp    *ptr;
    i = 0;
//t_ptr_list list;                                 ///////////////////////////////////////
//list.lst_a = ft_lst_next_gp(lst_a);    //////////////////////////////////////////////
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
            //printf("sfhjkh\n");
            ptr = ptr->next;
        }
        ptr->petit = 1;
    }



/*
while (list.lst_a)
{
printf("%d \n",list.lst_a->groupe);
list.lst_a = list.lst_a->prev;
}
*/

    return (i);
}

t_ptr_list    ft_divise_gp(t_ptr_list list, int nb_gp)
{
    int         i;
    int         groupe;

    i = 1;
    list.nb_gp = nb_gp;
    //list = ft_goupe_fusion(list);
    while(i <= list.nb_gp / 2)
    {
        list.lst_a = ft_lst_next_gp(list.lst_a);
        groupe = list.lst_a->groupe;
        list = ft_makeP_gp(FLAG_PB, list);
        list.instr = ft_creat_instr(FLAG_PB,list.instr);  
        list.lst_a = ft_lst_next_gp(list.lst_a);
        while(list.lst_a && (list.lst_a->groupe == groupe))
        {
            list.lst_a = list.lst_a->prev;
            list = ft_makeP_gp(FLAG_PB, list);
            list.instr = ft_creat_instr(FLAG_PB,list.instr);  
            list.lst_a = ft_lst_next_gp(list.lst_a);
        }
        //list = ft_goupe_fusion(list);
        i++;
    }
/*   t_ptr_list lst;
    lst.lst_a = ft_lst_next_gp(list.lst_a);

while (lst.lst_a)
{
printf("%d \n",lst.lst_a->groupe);
lst.lst_a = lst.lst_a->prev;
}*/
    //printf("jhfsdkj\n");*/
    return(list);
}

t_ptr_list    ft_fusion_gp(t_ptr_list list)
{
    int fin_a;
    int fin_b;

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
                    list = ft_makeP_gp(FLAG_PA, list);
                    list.instr = ft_creat_instr(FLAG_PA, list.instr);
                    list.lst_b = ft_lst_next_gp(list.lst_b);
                }
            }
            else if(!fin_b)
            {
                while (fin_a)
                {
                    if(list.lst_a->petit)
                        fin_a = 0;
                    ft_makeRR_gp(FLAG_RRA, list.lst_a, NULL);
                    list.instr = ft_creat_instr(FLAG_RRA, list.instr);
                    list.lst_a = ft_lst_prev_gp(list.lst_a);
                }
            }
            else
            {
                if(list.lst_a->nb > list.lst_b->nb)
                {
                    //printf("grand\n");
                    if(list.lst_a->petit)
                        fin_a = 0;
                    ft_makeRR_gp(FLAG_RRA, list.lst_a, NULL);
                    list.instr = ft_creat_instr(FLAG_RRA, list.instr);
                }
                else
                {
                    //printf("petit\n");
                    if(list.lst_b->petit)
                        fin_b = 0;
                    list = ft_makeP_gp(FLAG_PA, list);
                    list.instr = ft_creat_instr(FLAG_PA, list.instr);                    
                }
            }
            list.lst_b = ft_lst_next_gp(list.lst_b);
            list.lst_a = ft_lst_prev_gp(list.lst_a);
        }
    }
    return(list);
}
