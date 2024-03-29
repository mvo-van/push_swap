/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:25:09 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 13:12:50 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

void	ft_fail(char *buff, t_lst_instr *ptr_instr)
{
	t_lst_instr	*save;

	while (ptr_instr && ptr_instr->prev)
		ptr_instr = ptr_instr->prev;
	if (buff)
		free(buff);
	while (ptr_instr)
	{
		save = ptr_instr;
		ptr_instr = ptr_instr->next;
		free(save);
	}
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
