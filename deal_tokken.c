/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:01:33 by djulian           #+#    #+#             */
/*   Updated: 2020/01/08 15:18:48 by douatla          ###   ########.fr       */
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
		tokkens->string_tokken.empty_string = 1;
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

	if (value[0] == '-')
	{
		value_copy = ft_substr(value, 1, ft_strlen(value));
		if(!(value = (char*)malloc(precision_number + 1)))
			return (NULL);
		value[0] = '-';
		i = 0;
		len = ft_strlen(value_copy);
		while (++i < (precision_number - len))
			value[i] = '0';
		value[i] = '\0';
		ft_strlcat(value, value_copy, precision_number + 1);
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
	return(value);
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

char	*tokkens_int_precion_dot(char *value, int precision_number)
{
	char *value_copy;
	int len;
	int i;

	if (value[0] == '-')
	{
		value_copy = ft_substr(value, 1, ft_strlen(value));
		if(!(value = (char*)malloc(precision_number + 1)))
			return (NULL);
		value[0] = '-';
		i = 0;
		len = ft_strlen(value_copy);
		while (++i < (precision_number - len) + 1)
			value[i] = '0';
		value[i] = '\0';
		ft_strlcat(value, value_copy, precision_number + 2);
	}
	else
	{
		value_copy = ft_strdup(value);
		if(!(value = (char*)malloc(precision_number + 1)))
			return (NULL);
		i = -1;
		len = ft_strlen(value_copy);
		while(++i < (precision_number - len) + 1)
			value[i] = '0';
		value[i] = '\0';
		ft_strlcat(value, value_copy, precision_number + 2);
		// free(value_copy);
	}
	return (value);
}

char    *read_tokkens_struct(s_tokken *tokkens, char *value, va_list arg, int flag)
{
	// if (value[0] == 'Y') //cest de la merde
	// 	arg = arg + 1;
	if (tokkens->string_tokken.precision_zero_string == 1)
	{
		value = tokkens_preci_zero_string(tokkens, value);
		return (value);
	}
	if (tokkens->precision == 1 && flag == STRING)
		value = tokken_precision_string(tokkens->precision_number, value, tokkens);
	if (tokkens->int_tokken.precision_dot == 1)
		value = tokkens_int_precion_dot(value, tokkens->precision_number); //with precision .
	else if (tokkens->precision == 1 && (flag == INT_D || flag == POURCENT) && tokkens->precision_number != 0)
		value = tokken_precision_int(tokkens->precision_number, value); //with precision 0
	if (tokkens->adjustment != 0 && tokkens->left == 0)
		value = tokkens_adjustement_right(tokkens->adjustment, value);
	else if (tokkens->adjustment != 0 && tokkens->left == 1)
		value = tokkens_adjustement_left(tokkens->adjustment, value);
	return(value);
}