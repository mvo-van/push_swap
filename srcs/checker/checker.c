/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:34:09 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/06/08 10:53:49 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	t_lst_gp	*lst_nb;
	int			i;

	lst_nb = NULL;
	if (ac == 2)
	{
		i = 0;
		av = ft_strsplit(av[1], ' ');
		while (av[i])
			i++;
		ac = i + 1;
	}
	else if (ac > 2)
		av = av + 1;
	ac--;
	ft_verif_arg(av, ac);
	lst_nb = ft_creat_lst_gp(av, ac, lst_nb);
	lst_nb = ft_checker(lst_nb);
	ft_result(lst_nb, ac);
	return (0);
}

t_lst_gp	*ft_checker(t_lst_gp *lst_nb)
{
	char			*buff;
	t_lst_instr		*ptr_instr;
	t_save			save;

	ptr_instr = NULL;
	save.j = 0;
	while (get_next_line(0, &buff) > 0)
	{
		save.i = 0;
		while (buff[save.i])
		{
			if (buff[save.i] != '\n' && save.j < 3)
				save.str[save.j++] = buff[save.i];
			else
				exit(EXIT_FAILURE);
			save.i++;
		}
		if (buff[save.i] == '\0')
		{
			save.str[save.j] = '\0';
			save.j = 0;
			ptr_instr = ft_creat_instr(save, ptr_instr);
		}
	}
	return (ft_verif_instr(ptr_instr, lst_nb));
}

t_lst_gp	*ft_verif_instr(t_lst_instr *ptr_instr, t_lst_gp *lst_a)
{
	t_ptr_list		list;

	list.lst_a = lst_a;
	list.lst_b = NULL;
	while (ptr_instr && ptr_instr->prev)
		ptr_instr = ptr_instr->prev;
	while (ptr_instr)
	{
		if ((ptr_instr->flag & FLAG_SA) || (ptr_instr->flag & FLAG_SB))
			ft_makes_gp(ptr_instr->flag, list.lst_a, list.lst_b);
		else if ((ptr_instr->flag & FLAG_PA) || (ptr_instr->flag & FLAG_PB))
			list = ft_makep_gp(ptr_instr->flag, list);
		else if ((ptr_instr->flag & FLAG_RA) || (ptr_instr->flag & FLAG_RB))
			ft_maker_gp(ptr_instr->flag, list.lst_a, list.lst_b);
		else if ((ptr_instr->flag & FLAG_RRA) || (ptr_instr->flag & FLAG_RRB))
			ft_makerr_gp(ptr_instr->flag, list.lst_a, list.lst_b);
		ptr_instr = ptr_instr->next;
		list.lst_a = ft_lst_prev_gp(list.lst_a);
		list.lst_b = ft_lst_prev_gp(list.lst_b);
	}
	return (lst_a);
}

void		ft_result(t_lst_gp *lst_nb, int size)
{
	int i;

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

t_lst_gp	*ft_creat_lst_gp(char **av, int ac, t_lst_gp *lst_nb)
{
	int			i;
	int			*tab;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * ac)))
		return (NULL);
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		lst_nb = ft_creat_gp(lst_nb, tab[i - 1], ac);
		i++;
	}
	free(tab);
	return (lst_nb);
}
