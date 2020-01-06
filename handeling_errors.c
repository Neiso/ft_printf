/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handeling_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:06:27 by djulian           #+#    #+#             */
/*   Updated: 2019/12/30 12:35:53 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_minus_sign(const char *string, int index, int *ret)
{
	int remind;
	int nret;

	nret = *ret;
	if ((remind = find_pourcent_sign(string, ++index)))
	{
		while(index != remind)
		{
			if (!(ft_isdigit(string[index])))
			{
				nret += 1;
				write(1, &string[index], 1);
			}
			index++;
		}
		write(1, "%", 1);
		*ret = nret + 1;
		return (index + 1);
	}
	if (string[index + 1] == '%')
		return (index + 1);
	return (index);
}