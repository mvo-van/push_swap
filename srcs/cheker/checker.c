/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:09:48 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/11/15 15:52:10 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int			ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int			main(int ac, char **av)
{
	int			*tab;
	t_lst_gp	*lst_nb;
	int			i;

	lst_nb = NULL;
	if (ac == 2)
	{
		ac = ft_word(av[1], ' ') + 1;
		av = ft_strsplit2(av[1], ' ');
	}
	if (!(tab = (int*)malloc(sizeof(int) * (ac))))
		return (0);
	i = 0;
	while (++i != ac)
	{
		if (!(ft_verif_arg(tab, i, av[i])))
			return (ft_print_error());
		tab[i - 1] = ft_atoi(av[i]);
	}
	i = -1;
	while (++i < ac - 1)
		lst_nb = ft_creat_gp(lst_nb, tab[i], ac);
	lst_nb = ft_checker(lst_nb);
	ft_result(lst_nb, ac - 1);
	return (0);
}

t_lst_gp	*ft_checker(t_lst_gp *lst_nb)
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
				exit(EXIT_FAILURE);
		if (buff[save.i] == '\0')
		{
			save.str[save.j] = '\0';
			save.j = 0;
			ptr_instr = ft_creat_instr(save, ptr_instr, save.j);
		}
	}
	return (ft_verif_instr(ptr_instr, lst_nb));
}

t_lst_gp	*ft_verif_instr(t_lst_instr *ptr_instr, t_lst_gp *lst_a)
{
	t_ptr_list	list;

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
