/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2020/01/24 17:29:23 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tokkens_adjustement(int adjustement, char *value, int left)
{
	int i;
	int len;
	char *value_copy;

	len = (int)ft_strlen(value);
	value_copy = ft_strdup(value);
	if (adjustement <= len)
		return(value);
	if (!(value = (char*)malloc(adjustement + 1)))
		return (NULL);
	if(left)
	{	
		ft_strlcpy(value, value_copy, len + 1);
		i = len - 1;
		while (++i < adjustement)
			value[i] = ' ';
		value[i] = '\0';
	}
	else
	{
		i = -1;
		while(++i < (adjustement - len))
			value[i] = ' ';
		value[i] = '\0';
		ft_strlcat(value, value_copy, adjustement + 1);
	}
	free(value_copy);
	return(value);
}

char	*tokkens_int_precision(char *value, int precision_number, int precision)
{
	char *value_copy;
	int len;
	int i;
	int bool;

	if (ft_strlen(value) > precision_number)
		return(value);
	bool = (precision) ? -1 : 0;
	if (value[0] == '-')
	{
		value_copy = ft_substr(value, 1, ft_strlen(value));
		if(!(value = (char*)malloc(precision_number + 1)))
			return (NULL);
		value[0] = '-';
		i = 0;
		len = ft_strlen(value_copy) + bool;
		while (++i < (precision_number - len))
			value[i] = '0';
		value[i] = '\0';
		ft_strlcat(value, value_copy, precision_number + 1 - bool);
	}
	else
	{
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
	}
	return (value);
}



char	*tokken_precision_string(int precision_number, char *value, s_tokken *tokkens)
{
	if (precision_number == 0)
	{
		tokkens->string_tokken.empty_string = 1;
		return("");
	}
	if (precision_number > (int)ft_strlen(value))
		return (value);
	return (ft_substr((const char*)value, 0, precision_number));
}

char	*tokkens_preci_zero_string(s_tokken *tokkens, char *value)
{
	char	*zero;
	int		i;

	zero = NULL;
	if (tokkens->precision_number > 6)
	{
		if(!(zero = (char*)malloc(tokkens->precision_number - 6) + 1))
			return (NULL);
		i = -1;
		while (++i != tokkens->precision_number - 6)
			zero[i] = '0';
		zero[i] = '\0';
	}
	if (tokkens->precision_number > 6)
	{
		value = ft_strjoin(zero, value);
		// free(zero);
	}
	return (value);
}

char    *read_tokkens_struct(s_tokken *tokkens, char *value, va_list arg, int flag)
{
	if (tokkens->string_tokken.precision_zero_string == 1)
	{
		value = tokkens_preci_zero_string(tokkens, value);
		return (value);
	}
	if (tokkens->precision == 1 && flag == STRING)
		value = tokken_precision_string(tokkens->precision_number, value, tokkens);
	if ((tokkens->precision == 1 || tokkens->precision_zero == 1)&& (flag == INT_D || flag == POURCENT) && tokkens->precision_number != 0)
		value = tokkens_int_precision(value, tokkens->precision_number, tokkens->precision);
	if (tokkens->adjustment != 0)
		value = tokkens_adjustement(tokkens->adjustment, value, tokkens->left);
	return(value);
}