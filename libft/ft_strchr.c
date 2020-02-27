/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:25:02 by douatla           #+#    #+#             */
/*   Updated: 2019/10/19 15:12:16 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	to_find;

	i = 0;
	to_find = (char)c;
	while (s[i])
	{
		if (s[i] == to_find)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == '\0' && to_find == 0)
		return ((char*)&s[i]);
	return (0);
}
