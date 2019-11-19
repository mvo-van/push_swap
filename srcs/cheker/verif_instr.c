/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:25:09 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/05/07 17:25:29 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cheker.h"

void    ft_verifS(char c, t_lst_instr *instr)
{
    if(c == 's')
    {
        instr->flag |= FLAG_SA;
        instr->flag |= FLAG_SB;
    }
    else if(c == 'a')
        instr->flag |= FLAG_SA;
    else if(c == 'b')
        instr->flag |= FLAG_SB;
}

void    ft_verifP(char c, t_lst_instr *instr)
{
    if(c == 'a')
        instr->flag |= FLAG_PA;
    else if(c == 'b')
        instr->flag |= FLAG_PB;
}

void    ft_verifR(char c, t_lst_instr *instr)
{
    if(c == 'r')
    {
        instr->flag |= FLAG_RA;
        instr->flag |= FLAG_RB;
    }
    else if(c == 'a')
        instr->flag |= FLAG_RA;
    else if(c == 'b')
        instr->flag |= FLAG_RB;
}

void    ft_verifRR(char c, t_lst_instr *instr)
{
    if(c == 'r')
    {
        instr->flag |= FLAG_RRA;
        instr->flag |= FLAG_RRB;
    }
    else if(c == 'a')
        instr->flag |= FLAG_RRA;
    else if(c == 'b')
        instr->flag |= FLAG_RRB;
}
