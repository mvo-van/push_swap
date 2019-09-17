#include "push_swap.h"
#include <stdio.h>

/*
t_ptr_list    ft_goupe_fusion(t_ptr_list list)
{
    list.lst_a = ft_lst_next_gp(list.lst_a);
    if(list.lst_a && list.lst_a->prev && list.lst_a->grand && list.lst_a->petit 
        && list.lst_a->prev->grand && list.lst_a->prev->petit)
    {
        list.lst_a->grand = 0;
        list.lst_a->prev->petit = 0;
        list.lst_a->groupe = list.lst_a->prev->groupe;
        ft_makeS_gp(FLAG_SA,list.lst_a,NULL);
        list.instr = ft_creat_instr(FLAG_SA,list.instr);
        list.nb_gp--;
    }
    return(list);
}*/

t_lst_instr     *ft_prev_instr(t_lst_instr *instr)
{
    while (instr && instr->prev)
        instr = instr->prev;
    return(instr);
}
t_lst_instr     *ft_sup_P(t_lst_instr *instr)
{
    int             pa;
    int             pb;
    t_lst_instr     *ptr;
    t_lst_instr     *sav;

    ptr = instr;
    ptr = ft_prev_instr(ptr);
    while(ptr)
    {
        pa = 0;
        pb = 0;
        while (ptr && (ptr->flag & FLAG_RRA))
            ptr = ptr->next;
        while (ptr && (ptr->flag & FLAG_PA || ptr->flag & FLAG_PB))
        {   
            sav = ptr->next;
            if(ptr->flag == FLAG_PA)
                pa++;
            else
                pb++;
            if(pa && pb)
            {
                if(ptr->prev->prev)
                    ptr->prev->prev->next = ptr->next;
                if(ptr->next)
                    ptr->next->prev = ptr->prev->prev;
                if(instr == ptr || instr == ptr->prev)
                    instr = ptr->next;
                ft_free_instr(ptr->prev, 2);
                pa--;
                pb--;
            }
            ptr = sav;
        }
    }
    return (instr);
}

t_lst_instr    *ft_print_instr(t_lst_instr *instr)
{
    t_lst_instr     *save;

    instr = ft_sup_P(instr);
    instr = ft_prev_instr(instr);
    save = instr;
    while (instr)
    {
        if(instr->flag & FLAG_RRA)
            write(1,"rra\n",4);
        else if(instr->flag & FLAG_PA)
            write(1,"pa\n",3);        
        else if(instr->flag & FLAG_PB)
            write(1,"pb\n",3);
        instr = instr->next;
    }
    ft_free_instr(save, 0);
    return (NULL);        
}

void    ft_free_instr(t_lst_instr *ptr, int nb)
{
    if(nb > 0)
        while (ptr && nb)
        {
            free(ptr);
            ptr = ptr->next;
            nb--;
        }
    else
    {
        ptr = ft_prev_instr(ptr);
        while(ptr)
        {
            free(ptr);
            ptr = ptr->next;
        }
    }
}
