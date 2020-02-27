/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:03:34 by douatla           #+#    #+#             */
/*   Updated: 2019/10/25 16:21:46 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node_a;

	node_a = *lst;
	while (node_a->next != NULL)
	{
		ft_lstdelone(node_a, del);
		free(&node_a);
		node_a = node_a->next;
	}
	ft_lstdelone(node_a, del);
}
