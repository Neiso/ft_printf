/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:25:26 by douatla           #+#    #+#             */
/*   Updated: 2019/10/09 10:39:32 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	str = (char*)dst;
	str2 = (char*)src;
	i = 0;
	while (i < n)
	{
		str[i] = str2[i];
		if (str[i] == (char)c)
		{
			i++;
			return (&dst[i]);
		}
		i++;
	}
	return (NULL);
}
