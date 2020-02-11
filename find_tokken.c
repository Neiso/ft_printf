/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:05:24 by djulian           #+#    #+#             */
/*   Updated: 2020/02/11 12:18:52 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        print_tokken(s_tokken *tokkens)
{
	printf("\n%d\n", tokkens->adjustment);
	printf("%d\n", tokkens->left);
	printf("%d\n", tokkens->precision);
	printf("%d\n", tokkens->precision_number);
	printf("%d\n", tokkens->precision_zero);
	printf("%d\n", tokkens->precision_zero_number);
	printf("%d\n", tokkens->asterix);
	printf("%d\n", tokkens->asterix_2);
	printf("%d\n", tokkens->asterix_3);
	printf("%d\n", tokkens->error);
	printf("%c\n", tokkens->tokken);
	printf("%d\n", tokkens->string_tokken.empty_string);
	printf("%d\n", tokkens->string_tokken.precision_zero_string);
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
	tokkens->asterix = 0;
	tokkens->asterix_2 = 0;
	tokkens->asterix_3 = 0;
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


// int		asterix_tokken(s_tokken *tokkens, const char *string, char flag, va_list arg, int tokken)
// {
// 	if (tokkens->asterix == 1)
// 		tokkens->adjustment = va_arg(arg, int);
// 	if (tokkens->asterix_2 == 1)
// 		tokkens->precision_number = va_arg(arg, int);
// 	if (tokkens->adjustment < 0 && (tokkens->left = 1))
// 		tokkens->adjustment = -tokkens->adjustment;
// 	if (tokkens->precision_number < 0)
// 		tokkens->precision = 0;
// }


int		pre_fill_tokken_struct(s_tokken *tokkens, const char *string, char flag)
{
	int i;
	int tmp;

	i = 1;
	while (string[i] == '-' && ++i)
		tokkens->left = 1;
	tmp = i;
	if (string[i] == '0' && flag != 's' && tokkens->left == 0)
	{
		tmp = ++i;
		tokkens->precision_zero = 1;
		while (string[i] >= '0' && string[i] <= '9' && string[i] != flag)
			i++;
		tokkens->precision_number = ft_atoi(ft_substr(string, tmp, i));
	}
	if (string[i] == '0' && flag == 's' && tokkens->left == 0)
		i = string_arg_preci_zero(tokkens, string, i);
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
	i = pre_fill_tokken_struct(tokkens, string, flag);
	while (string[i] != flag) 
	{
		if (string[i] == '-')
		{
			if (string[i + 1] == '*' && ++i && ++i)
				tokkens->asterix = 1;
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
			if (string[i + 1] == '*' && ++i && ++i && (tokkens->precision = 1))
				tokkens->asterix_2 = 1;
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
			tokkens->asterix = 1;
		else if((tokkens->error = 1))
			return(tokkens);
	}
	return(tokkens);
}
