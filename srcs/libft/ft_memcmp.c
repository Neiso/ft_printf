/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:08:47 by douatla           #+#    #+#             */
/*   Updated: 2019/10/15 16:49:59 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	if (n == 0)
		return (0);
	str = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] == str2[i])
			i++;
		else
			return ((unsigned char)str[i] - str2[i]);
	}
	return (0);
}
