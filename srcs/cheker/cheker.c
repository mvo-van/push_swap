/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:23:08 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/07 17:23:19 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cheker.h"
        #include <stdio.h>
int main(int ac, char **av)
{   
 
    int         *tab;
    t_lst_nb    *lst_nb;
    int         i;


    i=1;
    lst_nb = NULL;

    if(!ft_verif_arg(av, ac))
    {  
        write(1, "Error\n", 6);
        return(0);
    }
    if(!(tab = (int *)malloc(sizeof (int) * ac - 1)))
        return (0);
    
    while(i < ac)
    {
        tab[i-1] = ft_atoi(av[i]);
        lst_nb = ft_creat_nb(lst_nb, tab[i-1], ac - 1);
        i++;
    }
    lst_nb = ft_cheker(lst_nb);
    ft_result(lst_nb, ac - 1);
    return(0);
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

t_lst_nb    *ft_cheker(t_lst_nb *lst_nb)
{
    char          buff[11];
    t_lst_instr   *ptr_instr;
    t_save        save;
    int           ret;
    
    ptr_instr = NULL;
    save.j = 0;
    while((ret = read(1, buff,10)))
    {
        save.i=0;
        buff[ret] = 0;
        while(buff[save.i])
        {
            if(buff[save.i] != '\n')
            {
                save.str[save.j] = buff[save.i];
                save.j++;
            }
            else
            {
                save.str[save.j] = '\0';
                save.j = 0;
                ptr_instr = ft_creat_instr(save, ptr_instr);
                //printf("%d\n",ptr_instr->flag);
            }
            save.i++;
        }
    }
    return (ft_verif_instr(ptr_instr, lst_nb));
}

t_lst_nb    *ft_verif_instr(t_lst_instr *ptr_instr, t_lst_nb *lst_a)
{
    t_lst_nb    *lst_b;

    lst_b = NULL;
    while(ptr_instr && ptr_instr->prev)
        ptr_instr = ptr_instr->prev;
    while(ptr_instr)
    {
        if((ptr_instr->flag & FLAG_SA) || (ptr_instr->flag & FLAG_SB))
            ft_makeS(ptr_instr->flag, lst_a, lst_b);
        else if((ptr_instr->flag & FLAG_PA) || (ptr_instr->flag & FLAG_PB))
            ft_makeP(ptr_instr->flag, lst_a, lst_b);
        else if((ptr_instr->flag & FLAG_RA) || (ptr_instr->flag & FLAG_RB))
            ft_makeR(ptr_instr->flag, lst_a, lst_b);
        else if((ptr_instr->flag & FLAG_RRA) || (ptr_instr->flag & FLAG_RRB))
            ft_makeRR(ptr_instr->flag, lst_a, lst_b);
        ptr_instr = ptr_instr->next;
        lst_a = ft_lst_prev(lst_a);
        lst_b = ft_lst_prev(lst_b);
    }
    return (lst_a);
}

void    ft_result(t_lst_nb *lst_nb,int size)
{
    int i;

    i = 0;
    while(lst_nb && lst_nb->next && i < size)
    {
        if(lst_nb->nb > lst_nb->next->nb)
        {
            write(1, "KO\n", 3);
            //write(1, "55\n", 3);
            return;
        }
        lst_nb = lst_nb->next;
        i++;
    }
    if (i < size - 1)
        write(1, "KO\n", 3);
    else
        write(1, "OK\n", 3);
}