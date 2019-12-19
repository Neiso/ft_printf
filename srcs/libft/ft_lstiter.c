/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:10:59 by douatla           #+#    #+#             */
/*   Updated: 2019/10/22 12:29:14 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node_a;

	node_a = lst;
	while (node_a->next != NULL)
	{
		f(node_a->content);
		node_a = node_a->next;
	}
	f(node_a->content);
}
