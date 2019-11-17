/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:08:05 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/14 17:28:28 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
