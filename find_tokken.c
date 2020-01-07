/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tokken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:05:24 by djulian           #+#    #+#             */
/*   Updated: 2020/01/07 17:54:05 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FLAG "cspdiuxX%"

void        print_tokken(s_tokken *tokkens)
{
	printf("\n%d\n", tokkens->adjustment);
	printf("%d\n", tokkens->left);
	printf("%d\n", tokkens->precision);
	printf("%d\n", tokkens->precision_number);
	printf("%d\n", tokkens->asterix);
	printf("%d\n", tokkens->error);
	printf("%d\n", tokkens->empty_string);
	printf("%d\n", tokkens->precision_zero_string);
	printf("\n");
}

s_tokken    *init_tokken(s_tokken *tokkens)
{
	tokkens->adjustment = 0;
	tokkens->left = 0;
	tokkens->precision = 0;
	tokkens->precision_number = 0;
	tokkens->asterix = 0;
	tokkens->error = 0;
	tokkens->empty_string = 0;
	tokkens->precision_zero_string = 0;
	return (tokkens);
}

void	string_arg_preci_zero(s_tokken *tokkens,const char *string)
{
	int i;

	tokkens->precision_zero_string = 1;
	i = 2;
	while (string[i] != 's')
	{
		if (string[i] == '-')
			tokkens->left = 1;
		i++;
	}
}

s_tokken    *fill_tokken_struct(s_tokken *tokkens, const char *string, int flags)
{
	int     i;
	int     tmp;
	char    flag;

	i = 1;
	flag = FLAG[flags];
	while (string[i] == '-')
	{
		tokkens->left = 1;
		i++;
	}
	if (string[i] == ' ')
	{
		tokkens->adjustment = -1;
		i++;
	}
	tmp = i;
	if (string[i] == '0' && (flags == INT_D || flags == INT_I || flags == POURCENT) && tokkens->left == 0)
	{
		i++;
		tmp = i;
		tokkens->precision = tokkens->precision + 1;
		while (string[i] >= '0' && string[i] <= '9' && string[i] != flag)
			i++;
		tokkens->precision_number = ft_atoi(ft_substr(string, tmp, i));
	}
	if (string[i] == '0' && (flags == STRING))
	{
		string_arg_preci_zero(tokkens, string);
		return (tokkens);
	}
	while (string[i] != flag && string[i] >= '0' && string[i] <= '9')
		i++;
	if (i != 1 && tokkens->adjustment == 0)
		tokkens->adjustment = ft_atoi(ft_substr(string, tmp, i));
	while (string[i] != flag) 
	{
		if (string[i] =='.')
		{
			i++;
			tmp = i;
			tokkens->precision = tokkens->precision + 1;
			while (string[i] >= '0' && string[i] <= '9' && string[i] != flag)
				i++;
			tokkens->precision_number = ft_atoi(ft_substr(string, tmp, i));
		}
		else if (string[i] == '*')
			{
				tokkens->asterix = tokkens->asterix + 1;
				i++;
			}
		else if (string[i] == '-')
			{
				tokkens->error = 1;
				return(tokkens);
			}
		else
		{
			tokkens->error = 1;
			return(tokkens);
		}
	}
	return(tokkens);
}
