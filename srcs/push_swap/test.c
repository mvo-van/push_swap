#include "push_swap.h"
#include <stdio.h>

int         ft_cmp_gp(t_lst_nb *lst)
{
    int     cmp;

    lst = ft_lst_next_nb(lst);
    if(!lst || lst->gp == 0)
        return (0);
    cmp = 1;
    while(lst->prev && lst->gp == lst->prev->gp)
    {
        cmp++;
        lst = lst->prev;
    }
    return (cmp);
}

int     ft_cmp_lst_nb(t_lst_nb *lst)
{
    lst = ft_lst_next_nb(lst);
    while (lst->prev)
    {
        if(lst->prev->gp != lst->gp)
            return(1);
        lst = lst->prev;
    }
    return(0);
    
}

t_ptr_lst   ft_divise_avb(t_ptr_lst ptr,int *tab)
{
    int     cmp;
    int     piv;
    int     nb_ra;

    nb_ra = 0;
    cmp = ft_cmp_gp(ptr.lst_a);
    //printf("cmp %d\n",cmp);
    piv = tab[cmp/2];
    while (cmp > 0)
    {
        ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
        if(ptr.lst_a->nb < piv)
        {   
            ptr.lst_a->gp++;
            ptr = ft_make_instr(ptr, FLAG_PB);
        }
        else
        {
            ptr = ft_make_instr(ptr, FLAG_RA);
            nb_ra++;
        }
        cmp--;
    }
    while (nb_ra > 0 && ft_cmp_lst_nb(ptr.lst_a))
    {
        ptr = ft_make_instr(ptr, FLAG_RRA);
        nb_ra--;
    }
    return(ptr);
}

t_ptr_lst   ft_divise_bva(t_ptr_lst ptr,int *tab)
{
    int     cmp;
    int     piv;

    cmp = ft_cmp_gp(ptr.lst_b);
    piv = tab[cmp/2];
    while (cmp > 0)
    {
        ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
        if(ptr.lst_b->nb >= piv)  
            ptr = ft_make_instr(ptr, FLAG_PA);
        else
        {
            ptr.lst_b->gp++;
            ptr = ft_make_instr(ptr, FLAG_RB);
        }
        cmp--;
    }
    return(ptr);
}

t_ptr_lst   ft_push_swap(t_ptr_lst ptr)
{
    int cmp;

    if((cmp = ft_cmp_gp(ptr.lst_a)) > 3)
    {
        ptr = ft_divise_avb(ptr, ptr.tab);
        while ((cmp = ft_cmp_gp(ptr.lst_b)) > 3)
            ptr = ft_divise_bva(ptr, ptr.tab);
        ptr = ft_save_b(ptr, cmp);
        ptr.tab += cmp;
    }
    else
    {
        ptr = ft_save_a(ptr, cmp);
        ptr.tab += cmp;
    }
    
    return(ptr);
}

void    ft_gp_zero(t_lst_nb *lst, int i)
{
    lst = ft_lst_next_nb(lst);
    while(lst && i > 0)
    {
        lst->gp = 0;
        lst=lst->prev;
        i--;
    }
}
t_ptr_lst   ft_make_instr_times(t_ptr_lst ptr,int flag, int times)
{
    while(times > 0)
    {
        ptr = ft_make_instr(ptr, flag);
        times--;
    }
    return(ptr);
}

int     ft_odre(int a, int b, int c)
{
    if (a < b && b < c)
        return(1);
    if (a < b && b > c && a < c)
        return (2);
    if (a > b && b < c && a < c)
        return (3);
    if (a < b && b > c && a > c)
        return (4);
    if (a > b && b < c && a > c)
        return (5);
    return(6);
}




/*int     ft_valide(t_ptr_lst ptr,int len)
{
    int i;

    i = 0;
    ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
    while (ptr.lst_a && i<len)
    {
        if(ptr.lst_a->nb != ptr.tab[i])
            return(1);
        ptr.lst_a = ptr.lst_a->prev;
        i++;
    }
    if(ptr.lst_a || i < len)
        return(1);
    return(0);
    
}*/

/*
int main()
{
    t_ptr_lst ptr;
    
    ptr.tab = (int*)malloc(sizeof(int)*8);
    ptr.tab[0] = 1;
    ptr.tab[1] = 2;
    ptr.tab[2] = 3;
    ptr.tab[3] = 4;
    ptr.tab[4] = 5;
    ptr.tab[5] = 6;
    ptr.tab[6] = 7;
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
    ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, 8);


    //ptr.lst_b = ft_creat_lst_nb(ptr.lst_b, 8);
    //ptr = ft_make_instr(ptr, FLAG_PB);
    //ft_print_list_nb(ptr);
    //printf("\n%d\n",ft_valide(ptr,7));
    //ptr = ft_divise_avb(ptr, tab);
    //ptr = ft_divise_bva(ptr, tab);
    //ptr = ft_make_instr_times(ptr,FLAG_PB, 5);
    //ptr = ft_push_swap(ptr);
    //ptr = ft_push_swap(ptr);
    //ptr = ft_push_swap(ptr);
    printf("%d\n",ft_valide(ptr, 7));
    //ft_print_list_nb(ptr);
    //printf("%d",ft_cmp_gp(ptr.lst_a));

}*/