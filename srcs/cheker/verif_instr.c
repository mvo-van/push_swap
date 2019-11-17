/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:25:09 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/15 16:35:39 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_verifs(char c, t_lst_instr *instr)
{
	if (c == 's')
	{
		instr->flag |= FLAG_SA;
		instr->flag |= FLAG_SB;
	}
	else if (c == 'a')
		instr->flag |= FLAG_SA;
	else if (c == 'b')
		instr->flag |= FLAG_SB;
	else
		return (0);
	return (1);
}

int		ft_verifp(char c, t_lst_instr *instr)
{
	if (c == 'a')
		instr->flag |= FLAG_PA;
	else if (c == 'b')
		instr->flag |= FLAG_PB;
	else
		return (0);
	return (1);
}

int		ft_verifr(char c, t_lst_instr *instr)
{
	if (c == 'r')
	{
		instr->flag |= FLAG_RA;
		instr->flag |= FLAG_RB;
	}
	else if (c == 'a')
		instr->flag |= FLAG_RA;
	else if (c == 'b')
		instr->flag |= FLAG_RB;
	else
		return (0);
	return (1);
}

int		ft_verifrr(char c, t_lst_instr *instr)
{
	if (c == 'r')
	{
		instr->flag |= FLAG_RRA;
		instr->flag |= FLAG_RRB;
	}
	else if (c == 'a')
		instr->flag |= FLAG_RRA;
	else if (c == 'b')
		instr->flag |= FLAG_RRB;
	else
		return (0);
	return (1);
}
