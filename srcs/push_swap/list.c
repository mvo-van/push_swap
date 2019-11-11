#include "push_swap.h"
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
/*void ft_print_list_nb(t_ptr_lst ptr)
{
    printf("\nAAAAAAAAAAAAA\n");
    ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
    ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
    while (ptr.lst_a)
    {
        printf("%d ", ptr.lst_a->nb);
        ptr.lst_a = ptr.lst_a->prev;
    }
    printf("\nBBBBBBBBBBBBBB\n");
    while (ptr.lst_b)
    {
        printf("%d ", ptr.lst_b->nb);
        ptr.lst_b = ptr.lst_b->prev;
    }
}*/
////////////////////////////////////////////////////////////////////////
t_lst_nb    *ft_creat_lst_nb(t_lst_nb   *lst_nb, int i)
{
    t_lst_nb    *new;

    if(!(new = (t_lst_nb*)malloc(sizeof(t_lst_nb) * 1)))
        return (NULL);
    if(lst_nb)
        lst_nb->prev = new;
    new->nb = i;
    new->gp = 1;
    new->next = lst_nb;
    new->prev = NULL;
    return (new);
}

t_lst_instr    *ft_creat_lst_instr(t_lst_instr  *lst_instr, int flag)
{
    t_lst_instr    *new;

    if(!(new = (t_lst_instr*)malloc(sizeof(t_lst_instr) * 1)))
        return (NULL);
    if(lst_instr)
        lst_instr->next = new;
    new->flag = flag;
    new->prev = lst_instr;
    new->next = NULL;
    return (new);
}

t_ptr_lst    ft_make_instr(t_ptr_lst ptr_lst, int flag)
{
    if(FLAG_PA & flag || FLAG_PB & flag)
        ptr_lst = ft_makeP_nb(flag, ptr_lst);
    else if(FLAG_SA & flag || FLAG_SB & flag)
        ft_makeS_nb(flag, ptr_lst.lst_a, ptr_lst.lst_b);
    else if(FLAG_RA & flag || FLAG_RB & flag)
        ft_makeR_nb(flag, ptr_lst.lst_a, ptr_lst.lst_b);
    else if(FLAG_RRA & flag || FLAG_RRB & flag)
        ft_makeRR_nb(flag, ptr_lst.lst_a, ptr_lst.lst_b);
    ptr_lst.lst_flag = ft_creat_lst_instr(ptr_lst.lst_flag, flag);
    //ft_print_list_nb(ptr_lst);
    //printf("%d\n", flag);
    return(ptr_lst);
}

t_lst_nb    *ft_lst_prev_nb(t_lst_nb *ptr)
{
    while(ptr && ptr->prev)
        ptr = ptr->prev;
    return(ptr);
}

t_lst_nb    *ft_lst_next_nb(t_lst_nb *ptr)
{
    while(ptr && ptr->next)
        ptr = ptr->next;
    return(ptr);
}
/*


void ft_print_list_instr(t_ptr_lst ptr)
{
    while (ptr.lst_flag && ptr.lst_flag->prev)
        ptr.lst_flag = ptr.lst_flag->prev;
    while (ptr.lst_flag)
    {
        printf("        %d\n", ptr.lst_flag->flag);
        ptr.lst_flag = ptr.lst_flag->next;
    }
}*/
/*
int main()
{
    t_ptr_lst ptr;

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

    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_PB);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_PB);    
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_PB);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_SA);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_SB);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_RA);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_RB);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_RRA);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_RRB);
    ft_print_list_nb(ptr);
    ptr = ft_make_instr(ptr, FLAG_PA);
    ft_print_list_nb(ptr);    
    ft_print_list_instr(ptr);
}*/