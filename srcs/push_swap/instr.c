#include "push_swap.h"
#include <stdio.h>

t_lst_instr *ft_lst_prev_instr(t_lst_instr *ptr)
{
    while (ptr && ptr->prev)
        ptr = ptr->prev;
    return (ptr);
}

t_ptr_lst_instr     ft_sav_zero(t_lst_instr *lst)
{
    t_ptr_lst_instr sav;

    sav.sa = NULL;
    sav.sb = NULL;
    sav.pa = NULL;
    sav.pb = NULL;
    sav.ra = NULL;
    sav.rb = NULL;
    sav.rra = NULL;
    sav.rrb = NULL;
    sav.lst = lst;
    return(sav);
}

t_lst *ft_creat(t_lst *lst, t_lst_instr *instr)
{
    t_lst *new;

    if(!(new = (t_lst*)malloc(sizeof(t_lst)*1)))
        return(NULL);
    if(lst)
        lst->next=new;
    new->next = NULL;
    new->ptr = instr;
    new->prev = lst;
    return(new);
}

t_lst   *ft_free_lst(t_lst *lst)
{
    t_lst   *sup;
    while(lst)
    {
        sup =  lst;
        lst = lst->prev;
        free(sup);
    }
    return (NULL);
}

t_ptr_lst_instr     ft_opti_SA(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.sa)
    {
        sav.sa->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.sa;
        sav.sa = sav.sa->prev;
        if(sav.sa)
            sav.sa->next = NULL;
        free(sup);
    }
    else
    {
        sav.pa = ft_free_lst(sav.pa);
        sav.pb = ft_free_lst(sav.pb);
        sav.ra = ft_free_lst(sav.ra);
        sav.rra = ft_free_lst(sav.rra);
        sav.sa = ft_creat(sav.sa, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_SB(t_ptr_lst_instr sav)
{
    t_lst *sup;

    if(sav.sb)
    {
        sav.sb->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.sb;
        sav.sb = sav.sb->prev;
        if(sav.sb)
            sav.sb->next = NULL;
        free(sup);
    }
    else
    {
        sav.pa = ft_free_lst(sav.pa);
        sav.pb = ft_free_lst(sav.pb);
        sav.rb = ft_free_lst(sav.rb);
        sav.rrb = ft_free_lst(sav.rrb);
        sav.sb = ft_creat(sav.sb, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_PA(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.pb)
    {
        sav.pb->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.pb;
        sav.pb = sav.pb->prev;
        if(sav.pb)
            sav.pb->next = NULL;
        free(sup);
    }
    else
    {
        sav.sa = ft_free_lst(sav.sa);
        sav.sb = ft_free_lst(sav.sb);
        sav.ra = ft_free_lst(sav.ra);
        sav.rb = ft_free_lst(sav.rb);
        sav.rra = ft_free_lst(sav.rra);
        sav.rrb = ft_free_lst(sav.rrb);
        sav.pa = ft_creat(sav.pa, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_PB(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.pa)
    {
        sav.pa->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.pa;
        sav.pa = sav.pa->prev;
        if(sav.pa)
            sav.pa->next = NULL;
        free(sup);
    }
    else
    {
        sav.sa = ft_free_lst(sav.sa);
        sav.sb = ft_free_lst(sav.sb);
        sav.ra = ft_free_lst(sav.ra);
        sav.rb = ft_free_lst(sav.rb);
        sav.rra = ft_free_lst(sav.rra);
        sav.rrb = ft_free_lst(sav.rrb);
        sav.pb = ft_creat(sav.pb, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_RA(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.rra)
    {
        sav.rra->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.rra;
        sav.rra = sav.rra->prev;
        if(sav.rra)
            sav.rra->next = NULL;
        free(sup);
    }
    else
    {
        sav.sa = ft_free_lst(sav.sa);
        sav.pa = ft_free_lst(sav.pa);
        sav.pb = ft_free_lst(sav.pb);
        sav.ra = ft_creat(sav.ra, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_RB(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.rrb)
    {
        sav.rrb->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.rrb;
        sav.rrb = sav.rrb->prev;
        if(sav.rrb)
            sav.rrb->next = NULL;
        free(sup);
    }
    else
    {
        sav.sb = ft_free_lst(sav.sb);
        sav.pa = ft_free_lst(sav.pa);
        sav.pb = ft_free_lst(sav.pb);
        sav.rb = ft_creat(sav.rb, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_RRA(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.ra)
    {
        sav.ra->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.ra;
        sav.ra = sav.ra->prev;
        if(sav.ra)
            sav.ra->next = NULL;
        free(sup);
    }
    else
    {
        sav.sa = ft_free_lst(sav.sa);
        sav.pa = ft_free_lst(sav.pa);
        sav.pb = ft_free_lst(sav.pb);
        sav.rra = ft_creat(sav.rra, sav.lst);
    }
    return(sav);
}

t_ptr_lst_instr ft_opti_RRB(t_ptr_lst_instr sav)
{
    t_lst *sup;
    
    if(sav.rb)
    {
        sav.rb->ptr->flag = 0;
        sav.lst->flag = 0;
        sup = sav.rb;
        sav.rb = sav.rb->prev;
        if(sav.rb)
            sav.rb->next = NULL;
        free(sup);
    }
    else
    {
        sav.sb = ft_free_lst(sav.sb);
        sav.pa = ft_free_lst(sav.pa);
        sav.pb = ft_free_lst(sav.pb);
        sav.rrb = ft_creat(sav.rrb, sav.lst);
    }
    return(sav);
}

t_lst_instr   *ft_opti_instr(t_lst_instr *lst)
{
    t_ptr_lst_instr sav;

    sav = ft_sav_zero(lst);
    sav.lst = ft_lst_prev_instr(sav.lst);
    while(sav.lst)
    {
        if(sav.lst->flag & FLAG_SA)
            sav = ft_opti_SA(sav);
        else if(sav.lst->flag & FLAG_SB)
            sav = ft_opti_SB(sav);
        else if(sav.lst->flag & FLAG_PA)
            sav = ft_opti_PA(sav);
        else if(sav.lst->flag & FLAG_PB)
            sav = ft_opti_PB(sav);
        else if(sav.lst->flag & FLAG_RA)
            sav = ft_opti_RA(sav);
        else if(sav.lst->flag & FLAG_RB)
            sav = ft_opti_RB(sav);
        else if(sav.lst->flag & FLAG_RRA)
            sav = ft_opti_RRA(sav);
        else if(sav.lst->flag & FLAG_RRB)
            sav = ft_opti_RRB(sav);    
        sav.lst = sav.lst->next;
    }
    return (lst);
}
/*
int main()
{
    t_ptr_lst     ptr;
    ptr.lst_a = NULL;
    ptr.lst_b = NULL;
    ptr.lst_flag = NULL;

    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 1);
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 2);
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 3);
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 4);
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 5);
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 6);
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 7);
    ptr = ft_make_instr(ptr, FLAG_SA);
    instr = ft_creat_lst_instr(instr, FLAG_SA);
    instr = ft_creat_lst_instr(instr, FLAG_RA);
    instr = ft_creat_lst_instr(instr, FLAG_PA);
    instr = ft_creat_lst_instr(instr, FLAG_RRA);

    
    //ft_opti_instr(instr);
    ft_print_instr(ptr.lst_flag);
    ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
    while(ptr.lst_a)
    {
        printf("%d \n",ptr.lst_a->nb);
        ptr.lst_a = ptr.lst_a->prev;
    }
    return(0);
}*/