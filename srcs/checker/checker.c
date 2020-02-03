/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:09:48 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 14:57:43 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

char		**ft_strsplit2(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (ft_word(s, c) + 2))))
		return (NULL);
	len = 0;
	j = 1;
	while (s[len])
	{
		i = 0;
		while (s[len] == c)
			len++;
		while (s[len] && s[len] != c)
		{
			i++;
			len++;
		}
		if (i != 0 && !(tab[j++] = ft_strsub(s, len - i, i)))
			return (NULL);
	}
	return (tab);
}

int			ft_print_error(int *tab, int sav, char **av, int ac)
{
	write(1, "Error\n", 6);
	ft_free(tab, sav, av, ac);
	return (0);
}

int			main(int ac, char **av)
{
	int			*tab;
	t_lst_gp	*lst_nb;
	int			i;
	int			sav;

	lst_nb = NULL;
	if ((sav = (ac == 2)))
	{
		ac = ft_word(av[1], ' ') + 1;
		av = ft_strsplit2(av[1], ' ');
	}
	if (!(tab = (int*)malloc(sizeof(int) * (ac))))
		return (ft_free(NULL, sav, av, ac));
	i = 0;
	while (++i != ac)
	{
		if (!(ft_verif_arg(tab, i, av[i])))
			return (ft_print_error(tab, sav, av, ac));
		tab[i - 1] = ft_atoi(av[i]);
	}
	i = -1;
	while (++i < ac - 1)
		lst_nb = ft_creat_gp(lst_nb, tab[i], ac);
	lst_nb = ft_checker(lst_nb, ac - 1);
	return (ft_free(tab, sav, av, ac));
}

t_lst_gp	*ft_checker(t_lst_gp *lst_nb, int ac)
{
	char		*buff;
	t_lst_instr	*ptr_instr;
	t_save		save;

	ptr_instr = NULL;
	save.j = 0;
	while (get_next_line(0, &buff) > 0)
	{
		save.i = -1;
		while (buff[++save.i])
			if (buff[save.i] != '\n' && save.j < 3)
			{
				save.str[save.j] = buff[save.i];
				save.j++;
			}
			else
				ft_fail(buff, ptr_instr);
		if (buff[save.i] == '\0')
		{
			save.str[save.j] = '\0';
			save.j = 0;
			ptr_instr = ft_creat_instr(save, ptr_instr, save.j, buff);
		}
	}
	return (ft_verif_instr(ptr_instr, lst_nb, ac));
}

t_lst_gp	*ft_verif_instr(t_lst_instr *i, t_lst_gp *la, int ac)
{
	t_ptr_list	list;
	t_lst_instr	*save;

	list.lst_a = la;
	list.lst_b = NULL;
	while (i && i->prev)
		i = i->prev;
	while (i)
	{
		save = i;
		if ((i->flag & FLAG_SA) || (i->flag & FLAG_SB))
			ft_makes_gp(i->flag, list.lst_a, list.lst_b);
		else if ((i->flag & FLAG_PA) || (i->flag & FLAG_PB))
			list = ft_makep_gp(i->flag, list);
		else if ((i->flag & FLAG_RA) || (i->flag & FLAG_RB))
			ft_maker_gp(i->flag, list.lst_a, list.lst_b);
		else if ((i->flag & FLAG_RRA) || (i->flag & FLAG_RRB))
			ft_makerr_gp(i->flag, list.lst_a, list.lst_b);
		i = i->next;
		list.lst_a = ft_lst_prev_gp(list.lst_a);
		list.lst_b = ft_lst_prev_gp(list.lst_b);
		free(save);
	}
	la = ft_result(la, ac, list.lst_b);
	return (la);
}
