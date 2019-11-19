#include "push_swap.h"

int    ft_print_error()
{
    write(1,"Error\n", 6);
    return(0);
}

t_lst_instr *ft_print_instr(t_lst_instr *instr)
{
    t_lst_instr     *save;

    instr = ft_lst_prev_instr(instr);
    while (instr)
    {   
        save = instr;
        if(instr->flag & FLAG_RRA)
            write(1,"rra\n",4);
        else if(instr->flag & FLAG_PA)
            write(1,"pa\n",3);        
        else if(instr->flag & FLAG_PB)
            write(1,"pb\n",3);
        else if(instr->flag & FLAG_RA)
            write(1,"ra\n",3);        
        else if(instr->flag & FLAG_RB)
            write(1,"rb\n",3);
        else if(instr->flag & FLAG_SA)
            write(1,"sa\n",3);        
        else if(instr->flag & FLAG_SB)
            write(1,"sb\n",3);
        else if(instr->flag & FLAG_RRB)
            write(1,"rrb\n",4);
        //else
        //    write(1,"0\n",2);
        
        instr = instr->next;
        if(instr)
            instr->prev = NULL;
        free(save);
    }
    return (NULL);
}
