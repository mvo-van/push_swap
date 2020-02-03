/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:29:26 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/01/10 14:59:02 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	ft_free(int *tab, int sav, char **av, int ac)
{
	int	i;

	i = 0;
	if (tab)
		free(tab);
	if (sav)
	{
		while (i < ac)
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	return (0);
}
