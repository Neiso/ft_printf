/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2019/12/26 13:58:17 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tokkens_adjustement_left(int adjustement, char *value)
{
	int i;

	char *value_copy;
	if (adjustement <= ft_strlen(value))
		return(value);
	value_copy = ft_strdup(value);
	if (!(value = (char*)malloc(adjustement + 1)))
		return (NULL);
	ft_strlcpy(value, value_copy, ft_strlen(value_copy) + 1);
	i = ft_strlen(value_copy) - 1;
	while (++i < adjustement)
		value[i] = ' ';
	value[i] = '\0';
	free(value_copy);
	return(value);
}
char	*tokkens_adjustement_right(int adjustement, char *value)
{
	int i;

	char *value_copy;
	if (adjustement <= ft_strlen(value))
		return(value);
	value_copy = ft_strdup(value);
	if (!(value = (char*)malloc(adjustement + 1)))
		return (NULL);
	i = -1;
	while(++i < (adjustement - ft_strlen(value_copy)))
		value[i] = ' ';
	value[i] = '\0';
	ft_strlcat(value, value_copy, adjustement + 1);
	free(value_copy);
	return (value);
}

char	*tokken_precision_string(int precision_number, char *value)
{
	if (precision_number > ft_strlen(value))
		return (value);
	return (ft_substr((const char*)value, 0, precision_number));
}

char	*tokken_precision_int(int precision_number, char *value)
{
	char *value_copy;
	int len;
	int i;

	value_copy = ft_strdup(value);
	if(!(value = (char*)malloc(precision_number + 1)))
		return (NULL);
	i = -1;
	len = ft_strlen(value_copy);
	while(++i < (precision_number - len))
		value[i] = '0';
	value[i] = '\0';
	ft_strlcat(value, value_copy, precision_number + 1);
	free(value_copy);
	return(value);
}

char    *read_tokkens_struct(s_tokken *tokkens, char *value, va_list arg, int flag)
{
	int i;

	i = 0;
	if (tokkens->precision == 1 && flag == STRING)
		value = tokken_precision_string(tokkens->precision_number, value);
	if (tokkens->precision == 1 && flag == DECIMAL_D)
		value = tokken_precision_int(tokkens->precision_number, value);
	if (tokkens->adjustment > 0 && tokkens->left == 0)
		value = tokkens_adjustement_right(tokkens->adjustment, value);
	else if (tokkens->adjustment > 0 && tokkens->left == 1)
		value = tokkens_adjustement_left(tokkens->adjustment, value);
	return(value);
}