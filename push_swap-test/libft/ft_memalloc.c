/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:14:56 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 16:44:51 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*src;
	size_t	i;

	i = 0;
	if (!(src = (char*)malloc(sizeof(*src) * size)))
		return (NULL);
	while (i < size)
	{
		src[i] = 0;
		i++;
	}
	return (src);
}
