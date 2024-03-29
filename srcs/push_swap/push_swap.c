/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:09:47 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 14:50:06 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**ft_strsplit2(char const *s, char c)
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

int		ft_verif(int *tab, int x, char *str)
{
	long	i;
	long	s;
	long	nb;

	nb = 0;
	i = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if ((nb * s < -2147483648) || (nb * s > 2147483647))
			return (0);
		i++;
	}
	while (--x > 0)
		if (x > 0 && nb * s == tab[x - 1])
			return (0);
	return (1);
}

int		ft_valide(t_ptr_lst ptr, int len)
{
	int		i;

	i = 0;
	ptr.lst_a = ft_lst_next_nb(ptr.lst_a);
	while (ptr.lst_a && ptr.lst_a->prev && i < len)
	{
		if (ptr.lst_a->nb > ptr.lst_a->prev->nb)
			return (1);
		ptr.lst_a = ptr.lst_a->prev;
		i++;
	}
	if (ptr.lst_b)
		return (1);
	return (0);
}

int		ft_arg(t_ptr_lst ptr, char **av, int ac, int *tab)
{
	int		i;

	i = 1;
	while (i != ac)
	{
		if (!(ft_verif(ptr.tab, i, av[i])))
			return (ft_print_error(tab));
		if (i > 0)
			ptr.tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int			i;
	t_ptr_lst	ptr;
	int			save;

	if ((save = (ac == 2)))
	{
		ac = ft_word(av[1], ' ') + 1;
		av = ft_strsplit2(av[1], ' ');
	}
	if (!(ptr.tab = (int*)malloc(sizeof(int) * (ac))))
		return (ft_free(save, av, ac));
	ptr = ft_t_ptr_lst_zero(ptr.tab);
	if (!(ft_arg(ptr, av, ac, ptr.tab)))
		return (ft_free(save, av, ac));
	i = 0;
	while (i < ac - 1)
	{
		ptr.lst_a = ft_creat_lst_nb(ptr.lst_a, ptr.tab[i]);
		i++;
	}
	ft_sort_int(ptr.tab, i);
	while (ft_valide(ptr, i))
		ptr = ft_push_swap(ptr);
	ft_opti_instr(ptr.lst_flag);
	return (ft_print_instr(ptr, save, av, ac));
}
