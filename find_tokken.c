/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:05:24 by djulian           #+#    #+#             */
/*   Updated: 2020/02/15 19:51:17 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        print_tokken(s_tokken *tokkens)
{
	printf("\nADJUSTMENT :\t\t%d\n", tokkens->adjustment);
	printf("LEFT :\t\t\t%d\n", tokkens->left);
	printf("PRECISION :\t\t%d\n", tokkens->precision);
	printf("PRECISION NUMBER :\t%d\n", tokkens->precision_number);
	printf("PRECISION ZERO :\t%d\n", tokkens->precision_zero);
	printf("PRECISION ZERO NUM :\t%d\n", tokkens->precision_zero_number);
	printf("ERROR :\t\t\t%d\n", tokkens->error);
	printf("TOKKEN :\t\t%c\n", tokkens->tokken);
	printf("STRING EMPTY :\t\t%d\n", tokkens->string_tokken.empty_string);
	printf("PRECI ZERO STRING :\t%d\n", tokkens->string_tokken.precision_zero_string);
	printf("\n");
}

s_tokken    *init_tokken(s_tokken *tokkens)
{
	tokkens->adjustment = 0;
	tokkens->left = 0;
	tokkens->precision = 0;
	tokkens->precision_number = 0;
	tokkens->precision_zero = 0;
	tokkens->precision_zero_number = 0;
	tokkens->error = 0;
	tokkens->tokken = 0;
	tokkens->string_tokken.empty_string = 0;
	tokkens->string_tokken.precision_zero_string = 0;
	return (tokkens);
}

int		string_arg_preci_zero(s_tokken *tokkens,const char *string, int pos)
{
	int tmp;
	
	tokkens->string_tokken.precision_zero_string = 1;
	tmp = pos;
	while(string[pos] != 's' && string[pos] >= '0' && string[pos] <= '9')
		pos++;
	if (tmp != pos)
		tokkens->precision_number = ft_atoi(ft_substr(string, tmp, pos));
	return pos;
}


int		asterix_tokken(s_tokken *tokkens, const char *string, va_list arg, int tokken)
{
	if (tokken == PRECISION && tokkens->precision_zero == 1)
	{
		tokkens->precision_zero_number = va_arg(arg, int); //si la valeur est negatif cest pour preci zero qui gagne sinon cest precision
		if (tokkens->precision_zero_number < 0)
			tokkens->precision_zero = 0;
		else
			tokkens->precision_number = tokkens->precision_zero_number;
	}
	else if (tokken == ADJUST_ZERO && tokkens->tokken == '%' && (tokkens->precision_zero = 1)) // MDR INSHALLAH
		tokkens->adjustment = va_arg(arg, int);
	else if (tokken == ADJUST_ZERO)
	{
		tokkens->precision_zero_number = va_arg(arg, int); //si la valeur est negative cest adjust + left si positif zero gagne
		if (tokkens->precision_zero_number > 0 && (tokkens->precision_zero = 1))
			tokkens->precision_number = tokkens->precision_zero_number;
		else if ((tokkens->left = 1))
			tokkens->adjustment = -tokkens->precision_zero_number;
		// print_tokken(tokkens);
	}
	else if (tokken == ADJUSTMENT)
		tokkens->adjustment = va_arg(arg, int);
	else if (tokken == PRECISION)
		tokkens->precision_number = va_arg(arg, int);
	else if (tokken == ZERO && tokkens->tokken == '%')
		tokkens->adjustment = va_arg(arg, int);
	else if (tokken == ZERO)
		tokkens->precision_number = va_arg(arg, int);
	return (1);
}


int		pre_fill_tokken_struct(s_tokken *tokkens, const char *string, char flag, va_list arg)
{
	int i;
	int tmp;

	i = 1;
	while (string[i] == '-' && ++i)
		tokkens->left = 1;
	tmp = i;
	if (string[i] == '0' && flag != 's' && tokkens->left == 0)
	{
		while (string[i] == '0')
			i++;
		tmp = i;
		while (string[i] >= '0' && string[i] <= '9' && string[i] != flag)
			i++;
		// printf("STRING[i] = %c\nTMP - I = %d\n", string[i], tmp-i);
		if (i - tmp == 0 && string[i] == '*' && string[i + 1] == '.' && ++i) // si il ya preci zero et preci normal le 0 est adjustment
			asterix_tokken(tokkens, string, arg, ADJUSTMENT);
		if (i - tmp == 0 && string[i] == '*' && ++i)
			asterix_tokken(tokkens, string, arg, ADJUST_ZERO);
		else if (string[i] == '*' && ++i && (tokkens->precision_zero = 1))
			asterix_tokken(tokkens, string, arg, ZERO);
		else if (i != 2 && (tokkens->precision_zero = 1))
			tokkens->precision_number = ft_atoi(ft_substr(string, tmp, i));
	}
	if (string[i] == '0' && flag == 's' && tokkens->left == 0)
		i = string_arg_preci_zero(tokkens, string, i);
	// tmp = i;
	while (string[i] != flag && string[i] >= '0' && string[i] <= '9')
		i++;
	if (i != 1 && tokkens->adjustment == 0)
		tokkens->adjustment = ft_atoi(ft_substr(string, tmp, i));
	return i;
}

s_tokken    *fill_tokken_struct(s_tokken *tokkens, const char *string, int flags, va_list arg)
{
	int     i;
	int     tmp;
	char    flag;

	i = 1;
	flag = FLAG[flags];
	i = pre_fill_tokken_struct(tokkens, string, flag, arg);
	// print_tokken(tokkens);
	while (string[i] != flag) 
	{
		if (string[i] == '-')
		{
			if (string[i + 1] == '*' && ++i && ++i)
				asterix_tokken(tokkens, string, arg, ADJUSTMENT);
			else
			{
				tmp = ++i;
				tokkens->left = 1;
				while (string[i] >= '0' && string[i] <= '9' && string[i] != flag)
					i++;
				tokkens->adjustment = ft_atoi(ft_substr(string, tmp, i));
			}
		}
		else if (string[i] == '.')
		{
			// if (string[i + 1] == '*' && string[i-1] == '*' && string[i - 2] == '0' && ++i && ++i)
			// {
			// 	tokkens->precision_zero = 1;
			// 	tokkens->precision_number = tokkens->adjustment;
			// 	tokkens->adjustment = 0;
			// }
			if (string[i + 1] == '*' && ++i && ++i && (tokkens->precision = 1))
				asterix_tokken(tokkens, string, arg, PRECISION);
			else
			{
				tmp = ++i;
				tokkens->precision = tokkens->precision + 1;
				while (string[i] >= '0' && string[i] <= '9' && string[i] != flag)
					i++;
				tokkens->precision_number = ft_atoi(ft_substr(string, tmp, i));
			}
		}
		else if (string[i] == '*' && ++i)
			asterix_tokken(tokkens, string, arg, ADJUSTMENT);
		else if((tokkens->error = 1))
			return(tokkens);
	}
	return(tokkens);
}
