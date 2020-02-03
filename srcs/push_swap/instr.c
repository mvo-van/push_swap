/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:08:05 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/12/05 16:32:39 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_lst_instr		*ft_lst_prev_instr(t_lst_instr *ptr)
{
	while (ptr && ptr->prev)
		ptr = ptr->prev;
	return (ptr);
}

t_lst			*ft_creat(t_lst *lst, t_lst_instr *instr)
{
	t_lst *new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst) * 1)))
		return (NULL);
	if (lst)
		lst->next = new;
	new->next = NULL;
	new->ptr = instr;
	new->prev = lst;
	return (new);
}

t_lst			*ft_free_lst(t_lst *lst)
{
	t_lst	*sup;

	while (lst)
	{
		sup = lst;
		lst = lst->prev;
		free(sup);
	}
	return (NULL);
}

t_ptr_lst		ft_save_b_seul_petit(t_ptr_lst ptr)
{
	ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
	if (ptr.lst_b->nb < ptr.lst_b->prev->nb)
		ptr = ft_make_instr(ptr, FLAG_SB);
	return (ptr);
}

t_ptr_lst		ft_tri_petit(t_ptr_lst ptr)
{
	int		cmp;
	int		cmp_div;

	cmp = ft_cmp_lst_nb(ptr.lst_a);
	cmp_div = (cmp / 2) + (cmp % 2);
	ptr = ft_make_instr_times(ptr, FLAG_PB, 2);
	ptr = ft_save_a_seul(ptr, cmp_div);
	ptr = ft_save_b_seul_petit(ptr);
	while (cmp)
	{
		ptr.lst_a = ft_lst_prev_nb(ptr.lst_a);
		ptr.lst_b = ft_lst_next_nb(ptr.lst_b);
		if ((ptr.lst_b && ptr.lst_b->nb > ptr.lst_a->nb)
			|| (ptr.lst_b && !cmp_div))
			ptr = ft_make_instr(ptr, FLAG_PA);
		else
		{
			ptr = ft_make_instr(ptr, FLAG_RRA);
			cmp_div--;
		}
		cmp--;
	}
	return (ptr);
}
