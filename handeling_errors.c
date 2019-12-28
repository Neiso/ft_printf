/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handeling_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:06:27 by djulian           #+#    #+#             */
/*   Updated: 2019/12/28 11:38:39 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_minus_sign(const char *string, int index)
{
	int remind;

	remind = index;
	if (string[index + 1] == '%')
	{
		return (index + 1);
	}	
}