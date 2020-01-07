/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2020/01/07 17:56:05 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tokkens_adjustement_left(int adjustement, char *value)
{
	int i;
	int len;
	char *value_copy;

	len = (int)ft_strlen(value);
	value_copy = ft_strdup(value);
	if (adjustement == -1)
	{
		if (!(value = (char*)malloc(2)))
			return (NULL);
		value[0] = ' ';
		value[1] = '\0';
		ft_strlcat(value, value_copy, len + 2);
		return (value);
	}
	if (adjustement <= len)
		return(value);
	if (!(value = (char*)malloc(adjustement + 1)))
		return (NULL);
	ft_strlcpy(value, value_copy, len + 1);
	i = len - 1;
	while (++i < adjustement)
		value[i] = ' ';
	value[i] = '\0';
	// free(value_copy);
	return(value);
}
char	*tokkens_adjustement_right(int adjustement, char *value)
{
	int i;
	int len;
	char *value_copy;

	len = (int)ft_strlen(value);
	value_copy = ft_strdup(value);
	if (adjustement == -1)
	{
		if (!(value = (char*)malloc(2)))
			return (NULL);
		value[0] = ' ';
		value[1] = '\0';
		ft_strlcat(value, value_copy, len + 2);
		return (value);
	}
	if (adjustement <= len)
		return(value);
	if (!(value = (char*)malloc(adjustement + 1)))
		return (NULL);
	i = -1;
	while(++i < (adjustement - len))
		value[i] = ' ';
	value[i] = '\0';
	ft_strlcat(value, value_copy, adjustement + 1);
	// free(value_copy);
	return (value);
}

char	*tokken_precision_string(int precision_number, char *value, s_tokken *tokkens)
{
	if (precision_number == 0)
	{
		tokkens->empty_string = 1;
		return("");
	}
	if (precision_number > (int)ft_strlen(value))
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
	// free(value_copy);
	return(value);
}

char	*tokkens_preci_zero_string(s_tokken *tokkens, char *value)
{
	// print_tokken(tokkens);
	if (tokkens->left == 0)
	{
		value = ft_strjoin("000", value);
		// printf("\n\nVALUE IS : %s\n\n", value);
	}
	return (value);
}

char    *read_tokkens_struct(s_tokken *tokkens, char *value, va_list arg, int flag)
{
	// if (value[0] == 'Y') //cest de la merde
	// 	arg = arg + 1;
	if (tokkens->precision_zero_string == 1)
	{
		value = tokkens_preci_zero_string(tokkens, value);
		return (value);
	}
	if (tokkens->precision == 1 && flag == STRING)
		value = tokken_precision_string(tokkens->precision_number, value, tokkens);
	if (tokkens->precision == 1 && (flag == INT_D || flag == POURCENT) && tokkens->precision_number != 0)
		value = tokken_precision_int(tokkens->precision_number, value);
	if (tokkens->adjustment != 0 && tokkens->left == 0)
		value = tokkens_adjustement_right(tokkens->adjustment, value);
	else if (tokkens->adjustment != 0 && tokkens->left == 1)
		value = tokkens_adjustement_left(tokkens->adjustment, value);
	return(value);
}