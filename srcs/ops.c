/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:15:09 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/20 18:42:33 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "list.h"

char	op_p(t_clst *from, t_clst *to)
{
	char	*t;

	if (!from->head || !from->size)
		return (0);
	insert_elem(to, pop_elem(from));
	t = "px\n";
	t[1] = to->name;
	write(1, t, 3);
	return (1);
}

char	op_rr(t_clst *lst)
{
	char	*t;

	if (!lst->head || !lst->size)
		return (0);
	lst->head = lst->head->prev;
	t = "rrx\n";
	t[2] = lst->name;
	write(1, t, 4);
	return (1);
}

char	op_r(t_clst *lst)
{
	char	*t;

	if (!lst->head || !lst->size)
		return (0);
	lst->head = lst->head->next;
	t = "rx\n";
	t[1] = lst->name;
	write(1, t, 3);
	return (1);
}

char	op_s(t_clst *lst)
{
	t_elem	*tmp;
	char	*t;

	if (!lst->head || lst->head == lst->head->next || lst->size < 2)
		return (0);
	tmp = pop_elem(lst);
	lst->head = lst->head->next;
	insert_elem(lst, tmp);
	lst->head = lst->head->prev;
	t = "sx\n";
	t[1] = lst->name;
	write(1, t, 3);
	return (1);
}