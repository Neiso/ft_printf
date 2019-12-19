/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:22:56 by douatla           #+#    #+#             */
/*   Updated: 2019/10/15 15:30:20 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}
