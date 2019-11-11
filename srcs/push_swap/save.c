#include "push_swap.h"
#include <stdio.h>

t_ptr_lst    ft_save_a2(t_ptr_lst ptr)
{
    ft_gp_zero(ptr.lst_a, 2);
    ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
    if(ptr.lst_a->nb > ptr.lst_a->prev->nb)
        ptr = ft_make_instr(ptr, FLAG_SA);
    ptr = ft_make_instr_times(ptr, FLAG_RA,2);
    return(ptr);
}

t_ptr_lst    ft_save_a3(t_ptr_lst ptr)
{
    int     ord;

    ft_gp_zero(ptr.lst_a, 3);
    ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
    ord = ft_odre(ptr.lst_a->nb, ptr.lst_a->prev->nb, ptr.lst_a->prev->prev->nb);
    if (ord == 1 || ord == 3)
    {
        if(ord == 3)
            ptr = ft_make_instr(ptr, FLAG_SA);
        ptr = ft_make_instr_times(ptr, FLAG_RA,3);
    }
    else if(ord == 2)
    {
        ptr = ft_make_instr(ptr, FLAG_RA);
        ptr = ft_make_instr(ptr, FLAG_SA);
        ptr = ft_make_instr_times(ptr, FLAG_RA,2);
    }
    else if(ord == 4)
    {
        ptr = ft_make_instr(ptr, FLAG_PB);
        ptr = ft_make_instr(ptr, FLAG_SA);
        ptr = ft_make_instr(ptr, FLAG_RA);
        ptr = ft_make_instr(ptr, FLAG_PA);
        ptr = ft_make_instr_times(ptr, FLAG_RA,2);
    }
    else
    {
        ptr = ft_make_instr(ptr, FLAG_PB);
        if(ord == 6)
            ptr = ft_make_instr(ptr, FLAG_SA);
        ptr = ft_make_instr_times(ptr, FLAG_RA,2);
        ptr = ft_make_instr(ptr, FLAG_PA);
        ptr = ft_make_instr(ptr, FLAG_RA);
    }
    return(ptr);
}

t_ptr_lst    ft_save_a(t_ptr_lst ptr, int cmp)
{
    if(cmp == 1)
    {
        ft_gp_zero(ptr.lst_a, cmp);
        ptr = ft_make_instr(ptr, FLAG_RA);
    }
    else if(cmp == 2)
        ptr = ft_save_a2(ptr);
    else if(cmp == 3)
        ptr = ft_save_a3(ptr);
    return(ptr);
}

t_ptr_lst    ft_save_b3(t_ptr_lst ptr)
{
    int     ord;

    ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
    ord = ft_odre(ptr.lst_a->nb, ptr.lst_a->prev->nb, ptr.lst_a->prev->prev->nb);
    if (ord == 1 || ord == 3)
        ptr = ft_make_instr(ptr, FLAG_RRB);
    else if(ord == 2)
        ptr = ft_make_instr(ptr, FLAG_RB);
    ptr = ft_make_instr_times(ptr, FLAG_PA, 3);
    return(ptr);
}

t_ptr_lst    ft_save_b(t_ptr_lst ptr, int cmp)
{
    if(cmp == 1)
        ptr = ft_make_instr(ptr, FLAG_PA);
    else if(cmp == 2)
        ptr = ft_make_instr_times(ptr, FLAG_PA, 2);
    else if(cmp == 3)
        ptr = ft_save_b3(ptr);
    ptr = ft_save_a(ptr, cmp);
    return(ptr);
}
