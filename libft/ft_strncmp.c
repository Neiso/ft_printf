/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:51:01 by douatla           #+#    #+#             */
/*   Updated: 2019/10/18 11:03:44 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n == 0)
		return (0);
	c1 = s1[i];
	c2 = s2[i];
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (c1 != c2)
			return (c1 - c2);
		i++;
		c1 = s1[i];
		c2 = s2[i];
	}
	if (s1[i] == s2[i])
		return (0);
	return (c1 - c2);
}
