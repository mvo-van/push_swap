/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:24:52 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/20 19:51:58 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int		push_back(t_clst *lst, int value)
{
    t_elem	*new;
	t_elem	*head;

    if (!(new = malloc(sizeof(t_elem))))
        return (0);
	new->v = value;
	if ((head = lst->head))
	{
		new->next = head;
		new->prev = head->prev;
		head->prev->next = new;
		head->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		lst->head = new;
	}
	++lst->size;
	return (1);
}

void	insert_elem(t_clst *lst, t_elem *elem)
{
	t_elem	*prv;
	t_elem	*nxt;

	if (!elem)
		return ;
	nxt = lst->head;
	if (lst->head)
		prv = nxt->prev;
	else
	{
		prv = elem;
		nxt = elem;
	}
	prv->next = elem;
	nxt->prev = elem;
	elem->next = nxt;
	elem->prev = prv;
	lst->head = elem;
	++lst->size;
}

int		*to_tab(t_clst *lst, int size)
{
	int		i;
	int		*res;
	t_elem	*e;

	if (size > lst->size || !(res = malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	e = lst->head;
	while (i < lst->size && i < size)
	{
		res[i] = e->v;
		e = e->next;
		++i;	
	}
	return (res);
}

void	clear_list(t_clst *lst)
{
	t_elem	*e;

	while (lst->size--)
	{
		e = lst->head;
		lst->head = e->next;
		free(e);
	}
	lst->head = NULL;
}

t_elem	*pop_elem(t_clst *lst)
{
	t_elem	*elem;
	t_elem	*prv;
	t_elem	*nxt;

	if (lst->size <= 0)
		return (NULL);
	elem = lst->head;
	prv = elem->prev;
	nxt = elem->next;
	elem->next = elem;
	elem->prev = elem;
	prv->next = nxt;
	nxt->prev = prv;
	lst->head = nxt;
	if (--lst->size == 0)
		lst->head = NULL;
	return (elem);
}

t_elem	*find_max(t_clst *lst)
{
	int		i;
	t_elem	*e;
	t_elem	*res;

	i = 0;
	e = lst->head;
	res = e;
	while (i++ < lst->size)
	{
		e = e->next;
		if (e->v > res->v)
			res = e;
	}
	return (res);
}

t_elem	*find_min(t_clst *lst)
{
	int		i;
	t_elem	*e;
	t_elem	*res;

	i = 0;
	e = lst->head;
	res = e;
	while (i++ < lst->size)
	{
		e = e->next;
		if (e->v < res->v)
			res = e;
	}
	return (res);
}