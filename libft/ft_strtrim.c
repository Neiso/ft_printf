/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:48:46 by douatla           #+#    #+#             */
/*   Updated: 2019/10/19 15:40:12 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		difference(int i, int remind)
{
	if (remind - i > 0)
		return (remind - i);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	remind;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]))
		i++;
	remind = ft_strlen(s1);
	while (ft_strchr(set, s1[remind]) && remind != 0)
		remind--;
	if (!(str = (char*)malloc(difference(i, remind) + 2)))
		return (NULL);
	while (i <= remind)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
