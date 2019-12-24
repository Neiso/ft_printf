/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2019/12/24 15:28:33 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tokkens_precision(int precision_number, char *value)
{
	if (precision_number > ft_strlen(value))
		return (value);
	else if (precision_number == 0)
		return (value)
	
}

char    *read_tokkens_struct(s_tokken *tokkens, char *value, va_list arg)
{
	int i;

	i = 0;
	if (tokkens->precision == 1)
		value = tokkens_precision(tokkens->precision_number, value);
	return(value); 
}