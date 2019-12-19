/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:56:17 by douatla           #+#    #+#             */
/*   Updated: 2019/10/25 11:40:26 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*now;

	i = 0;
	if (lst == NULL)
		return (0);
	now = lst;
	while (now->next != NULL)
	{
		i++;
		now = now->next;
	}
	i++;
	return (i);
}
