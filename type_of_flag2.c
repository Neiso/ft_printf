/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:45:56 by djulian           #+#    #+#             */
/*   Updated: 2019/12/23 16:56:15 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer_arg(const char* string, va_list list_arg)
{
	unsigned int value;
	char *value_string;

	(void) string;
	value = va_arg(list_arg, unsigned int);
	value_string = ft_itoa_base16((unsigned int)value);
	if (value_string == NULL)
		return(0);
	value_string = ft_strjoin("0x", value_string);	
	write(1, value_string, ft_strlen(value_string));
	return (0);
}