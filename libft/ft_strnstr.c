/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:37:18 by douatla           #+#    #+#             */
/*   Updated: 2019/10/08 18:11:15 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	j = 0;
	while (haystack[j] && len != 0)
	{
		i = 0;
		k = j;
		while (haystack[k] == needle[i] && haystack[k] && needle[i] && i < len)
		{
			k++;
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j]);
		j++;
		len--;
	}
	return (0);
}
