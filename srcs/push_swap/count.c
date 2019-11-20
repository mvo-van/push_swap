/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:27:56 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/20 17:38:04 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/push_swap.h"
#include "list.h"

int			ft_cmp_gp(t_lst_nb *lst)
{
	int	cmp;

	lst = ft_lst_next_nb(lst);
	if (!lst || lst->gp == 0)
	{
		if(lst)
			printf("gp %d\n", lst->gp);
		else
		{
			printf("NULL\n");
		}
		return (0);
	}
	cmp = 1;
	while (lst->prev && lst->gp == lst->prev->gp)
	{
		cmp++;
		lst = lst->prev;
	}
	return (cmp);
}

int			ft_cmp_lst_gp(t_lst_nb *lst)
{
	lst = ft_lst_next_nb(lst);
	while (lst->prev)
	{
		if (lst->prev->gp != lst->gp)
			return (1);
		lst = lst->prev;
	}
	return (0);
}

int			ft_odre(int a, int b, int c)
{
	if (a < b && b < c)
		return (1);
	if (a < b && b > c && a < c)
		return (2);
	if (a > b && b < c && a < c)
		return (3);
	if (a < b && b > c && a > c)
		return (4);
	if (a > b && b < c && a > c)
		return (5);
	return (6);
}

t_ptr_lst	ft_t_ptr_lst_zero(void)
{
	t_ptr_lst	ptr;

	ft_bzero(&ptr.la, sizeof(t_lst));
	ft_bzero(&ptr.lb, sizeof(t_lst));
	ptr.la.name = 'a';
	ptr.lb.name = 'b';
	ptr.lst_a = NULL;
	ptr.lst_b = NULL;
	ptr.lst_flag = NULL;
	return (ptr);
}

int			ft_cmp_lst_nb(t_lst_nb *lst)
{
	int		i;

	i = 0;
	lst = ft_lst_next_nb(lst);
	while (lst)
	{
		lst = lst->prev;
		i++;
	}
	return (i);
}
