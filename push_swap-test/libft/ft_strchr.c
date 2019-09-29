/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:17:33 by mvo-van-          #+#    #+#             */
/*   Updated: 2018/11/20 16:32:32 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (s2[i] && s2[i] != c)
		i++;
	if (s2[i] || (c == '\0'))
		return (&s2[i]);
	return (NULL);
}