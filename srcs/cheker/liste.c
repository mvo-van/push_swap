/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:24:41 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/15 15:57:23 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_lst_instr	*ft_creat_instr(t_save save, t_lst_instr *lst_instr, int ret)
{
	t_lst_instr	*new;

	if ((new = (t_lst_instr *)malloc(sizeof(t_lst_instr) * 1)))
	{
		if (lst_instr)
			lst_instr->next = new;
		new->flag = 0;
		new->prev = lst_instr;
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
	if (!ret)
		exit(EXIT_FAILURE);
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

void		ft_result(t_lst_gp *lst_nb, int size)
{
	int		i;

	i = 0;
	lst_nb = ft_lst_prev_gp(lst_nb);
	while (lst_nb && lst_nb->next && i < size - 1)
	{
		if (lst_nb->nb < lst_nb->next->nb)
		{
			write(1, "KO\n", 3);
			return ;
		}
		lst_nb = lst_nb->next;
		i++;
	}
	if (i < size - 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
