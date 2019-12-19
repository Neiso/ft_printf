/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:27:09 by douatla           #+#    #+#             */
/*   Updated: 2019/10/18 10:36:53 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t return_value;

	i = ft_strlen(dst);
	j = 0;
	return_value = 0;
	if (i > size)
		return_value = size + ft_strlen(src);
	else
		return_value = ft_strlen(dst) + ft_strlen(src);
	while (src[j] && i < size - 1 && size != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (return_value);
}
