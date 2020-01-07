/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:50:07 by douatla           #+#    #+#             */
/*   Updated: 2020/01/07 17:01:05 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "srcs/libft/libft.h"
# define CHARACTER 0
# define STRING 1
# define POINTER 2
# define INT_D 3
# define INT_I 4
# define UNSI_INT 5
# define HEXA_x 6
# define HEXA_X 7
# define POURCENT 8
# define EMPTY_STRING -1

typedef struct s_tokken
{
    int     adjustment;
    int     left; //if == 0 so its adjust right
    int     precision;
    int     precision_number;
    int     asterix;
    int     error;
    int     empty_string;
    int     precision_zero_string;
}               s_tokken;

/*
**      ===================
**     |    ft_printf.c    |
**      ===================
*/

int		ft_printf(const char *string, ...);

/*
**-------------------------------------------------------------------
*/

/*
**      ===================
**     |    check_flag.c   |
**      ===================
*/

int     	deal_with_arg(const char *string, va_list list_arg);
char	    *ft_strjoin_pourcent(char *buffer);
char	    *find_next_arg(char *string);
int 		type_of_arg(const char *str);

/*
**-------------------------------------------------------------------
*/

/*
**      ======================
**     |    type_of_flag.c    |
**      ======================
*/

int     character_arg(const char* string, va_list list_arg, s_tokken *tokkens);
int     string_arg(const char* string, va_list list_arg, s_tokken *tokkens);
int     int_decimal_arg(const char* string, va_list list_arg, s_tokken *tokkens);
int     unsigned_int_decimal_arg(const char* string, va_list list_arg, s_tokken *tokkens);
int     unsigned_hexadecimal_arg(const char* string, va_list list_arg, s_tokken *tokkens);

/*
**-------------------------------------------------------------------
*/

/*
**      =======================
**     |    type_of_flag2.c    |
**      =======================
*/

/*
**-------------------------------------------------------------------
*/

int     pointer_arg(const char* string, va_list list_arg, s_tokken *tokkens);
int		pourcent_arg(const char* string, va_list list_arg, s_tokken *tokkens);

/*
**      ===============
**     |    utils.c    |
**      ===============
*/

char    *ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_base16(unsigned int n);

/*
**-------------------------------------------------------------------
*/

s_tokken    *fill_tokken_struct(s_tokken *tokkens, const char *string, int flags);
s_tokken    *init_tokken(s_tokken *tokkens);
void        print_tokken(s_tokken *tokkens);
char    *read_tokkens_struct(s_tokken *tokkens, char *value, va_list arg, int flag);
char	*tokkens_precision(int precision_number, char *value);
void	count_character_for_return (s_tokken *tokkens, char *value);
int		find_minus_sign(const char *string, int index, int *ret);
int		find_pourcent_sign(const char *string, int index);





//https://www.hackerearth.com/practice/notes/know-our-printf-variable-number-of-arguments-to-a-function/
#endif