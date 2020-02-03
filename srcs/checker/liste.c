/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:24:41 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/14 16:59:11 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_lst_gp	*ft_creat_gp(t_lst_gp *lst_nb, int i, int size)
{
	t_lst_gp	*new;

	if ((new = (t_lst_gp *)malloc(sizeof(t_lst_gp) * 1)))
	{
		if (lst_nb)
			lst_nb->prev = new;
		new->next = lst_nb;
		new->nb = i;
		new->size = size;
		new->prev = NULL;
	}
	return (new);
}

t_lst_instr	*ft_creat_instr(t_save save, t_lst_instr *i, int ret, char *t)
{
	t_lst_instr	*new;

	if ((new = (t_lst_instr *)malloc(sizeof(t_lst_instr) * 1)))
	{
		if (i)
			i->next = new;
		new->flag = 0;
		new->prev = i;
		if (ft_strlen(save.str) == 2)
		{
			if (save.str[0] == 's')
				ret = ft_verifs(save.str[1], new);
			else if (save.str[0] == 'p')
				ret = ft_verifp(save.str[1], new);
			else if (save.str[0] == 'r')
				ret = ft_verifr(save.str[1], new);
		}
		else if (save.str[0] == 'r' && save.str[1] == 'r')
			ret = ft_verifrr(save.str[2], new);
		new->next = NULL;
	}
	free(t);
	if (!ret)
		ft_fail(NULL, i);
	return (new);
}

t_lst_gp	*ft_lst_prev_gp(t_lst_gp *ptr)
{
	while (ptr && ptr->prev)
		ptr = ptr->prev;
	return (ptr);
}

t_lst_gp	*ft_lst_next_gp(t_lst_gp *ptr)
{
	while (ptr && ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_lst_gp	*ft_result(t_lst_gp *lst_a, int size, t_lst_gp *lb)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	lst_a = ft_lst_prev_gp(lst_a);
	while (lst_a && lst_a->next && i < size - 1)
	{
		if (j == 0 && lst_a->nb < lst_a->next->nb && ++j)
			write(1, "KO\n", 3);
		lst_a = lst_a->next;
		i++;
	}
	if (!lb && !lst_a)
		return (NULL);
	else if (j == 0 && i < size - 1)
		write(1, "KO\n", 3);
	else if (j == 0)
		write(1, "OK\n", 3);
	if (lb)
		lb = ft_free_gp(lb);
	if (lst_a)
		lst_a = ft_free_gp(lst_a);
	return (NULL);
}
