/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:52:30 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/20 19:56:03 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "list.h"

void		select_sort(int *tab, size_t size, int max)
{
	size_t	j;
	size_t	i;
	int		min1;
	int		mint;

	i = 0;
	min1 = -2147483648;
	while (i < size)
	{
		j = 0;
		mint = max;
		while (j < size)
		{
			if (tab[size + j] >= min1 && tab[size + j] < mint)
				mint = tab[size + j];
			j++;
		}
		tab[i++] = mint;
		min1 = mint + 1;
	}
}

static int get_pivot(t_clst *lst, int size)
{
	int		i;
	t_elem	*e;
	int		*tab;

	i = 0;
	e = lst->head;
	if (!(tab = ft_memalloc(sizeof(int) * (size * 2))))
		return (find_max(lst)->v / 2);
	while (i < size)
	{
		tab[size + i++] = e->v;
		e = e->next;
	}
	select_sort(tab, size, find_max(lst)->v);
	i = tab[size / 2];
	free(tab);
	return (i);
}

char		qsort_la(t_clst *l1, t_clst *l2, int size)
{
	int	pivot;

	if (size <= 3)
		return (1); //constant sort later
	pivot = get_pivot(l1, size);
	printf("pivot is %d\n", pivot);
	(void)l2;
	return (0);
}

/*
static char	qsort_lb(t_clst *l1, t_clst *l2, int size)
{
	int	pivot;

	if (size <= 3)
		return (1); //constant sort later
	pivot = get_pivot(l1, NULL, size);
	printf("pivot is %d\n", pivot);
	(void)l2;
	return (0);
}
*/
