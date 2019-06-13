/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:36:47 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/06/08 10:55:35 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_verif_s(char c, t_lst_instr *instr)
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

int		ft_verif_p(char c, t_lst_instr *instr)
{
	if (c == 'a')
		instr->flag |= FLAG_PA;
	else if (c == 'b')
		instr->flag |= FLAG_PB;
	else
		return (0);
	return (1);
}

int		ft_verif_r(char c, t_lst_instr *instr)
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

int		ft_verif_rr(char c, t_lst_instr *instr)
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
