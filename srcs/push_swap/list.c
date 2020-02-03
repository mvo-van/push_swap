/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:09:07 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/12/04 15:59:32 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lst_nb		*ft_creat_lst_nb(t_lst_nb *lst_nb, int i)
{
	t_lst_nb	*new;

	if (!(new = (t_lst_nb*)malloc(sizeof(t_lst_nb) * 1)))
		return (NULL);
	if (lst_nb)
		lst_nb->prev = new;
	new->nb = i;
	new->gp = 1;
	new->next = lst_nb;
	new->prev = NULL;
	return (new);
}

t_lst_instr		*ft_creat_lst_instr(t_lst_instr *lst_instr, int flag)
{
	t_lst_instr	*new;

	if (!(new = (t_lst_instr*)malloc(sizeof(t_lst_instr) * 1)))
		return (NULL);
	if (lst_instr)
		lst_instr->next = new;
	new->flag = flag;
	new->prev = lst_instr;
	new->next = NULL;
	return (new);
}

t_ptr_lst		ft_make_instr(t_ptr_lst ptr_lst, int flag)
{
	ptr_lst.lst_a = ft_lst_next_nb(ptr_lst.lst_a);
	ptr_lst.lst_b = ft_lst_next_nb(ptr_lst.lst_b);
	if (FLAG_PA & flag || FLAG_PB & flag)
		ptr_lst = ft_make_p_nb(flag, ptr_lst);
	else if (FLAG_SA & flag || FLAG_SB & flag)
		ft_make_s_nb(flag, ptr_lst.lst_a, ptr_lst.lst_b);
	else if (FLAG_RA & flag || FLAG_RB & flag)
		ft_make_r_nb(flag, ptr_lst.lst_a, ptr_lst.lst_b);
	else if (FLAG_RRA & flag || FLAG_RRB & flag)
		ft_make_rr_nb(flag, ptr_lst.lst_a, ptr_lst.lst_b);
	ptr_lst.lst_flag = ft_creat_lst_instr(ptr_lst.lst_flag, flag);
	return (ptr_lst);
}

t_lst_nb		*ft_lst_prev_nb(t_lst_nb *ptr)
{
	while (ptr && ptr->prev)
		ptr = ptr->prev;
	return (ptr);
}

t_lst_nb		*ft_lst_next_nb(t_lst_nb *ptr)
{
	while (ptr && ptr->next)
		ptr = ptr->next;
	return (ptr);
}
