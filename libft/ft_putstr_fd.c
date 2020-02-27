/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:17:31 by douatla           #+#    #+#             */
/*   Updated: 2019/10/15 15:25:17 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;
	int size;

	if (s == NULL)
		return ;
	i = 0;
	size = ft_strlen(s);
	while (i != size)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
