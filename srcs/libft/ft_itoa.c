/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:47:22 by douatla           #+#    #+#             */
/*   Updated: 2019/10/17 11:45:41 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	tmp;

	tmp = (long)n;
	i = 1;
	while ((tmp = tmp / 10))
		i++;
	if (n != 0 && (!(str = (char*)malloc(i + 2))))
		return (NULL);
	if (n == 0 && (!(str = (char*)malloc(i + 1))))
		return (NULL);
	i = n < 0 ? i + 1 : i;
	str[i] = '\0';
	str[0] = n < 0 ? '-' : '\0';
	tmp = n < 0 ? -(long)n : (long)n;
	i--;
	str[i] = n == 0 ? '0' : '\0';
	while (tmp)
	{
		str[i] = (char)((tmp % 10) + 48);
		tmp = tmp / 10;
		i--;
	}
	return (str);
}
