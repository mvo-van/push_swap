/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:09:35 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/14 18:21:56 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void			ft_instr(t_lst_instr *instr)
{
	if (instr->flag & FLAG_RRA)
		write(1, "rra\n", 4);
	else if (instr->flag & FLAG_PA)
		write(1, "pa\n", 3);
	else if (instr->flag & FLAG_PB)
		write(1, "pb\n", 3);
	else if (instr->flag & FLAG_RA)
		write(1, "ra\n", 3);
	else if (instr->flag & FLAG_RB)
		write(1, "rb\n", 3);
	else if (instr->flag & FLAG_SA)
		write(1, "sa\n", 3);
	else if (instr->flag & FLAG_SB)
		write(1, "sb\n", 3);
	else if (instr->flag & FLAG_RRB)
		write(1, "rrb\n", 4);
}

t_lst_instr		*ft_print_instr(t_lst_instr *instr)
{
	t_lst_instr	*save;

	instr = ft_lst_prev_instr(instr);
	while (instr)
	{
		save = instr;
		ft_instr(instr);
		instr = instr->next;
		if (instr)
			instr->prev = NULL;
		free(save);
	}
	return (NULL);
}
