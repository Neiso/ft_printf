/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:50:07 by douatla           #+#    #+#             */
/*   Updated: 2020/02/16 20:12:45 by douatla          ###   ########.fr       */
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
# define HEXA_XS 6
# define HEXA_X 7
# define POURCENT 8

# define MINUS_SIGN 9
# define PRECISION 10
# define ZERO 11
# define ADJUSTMENT 12
# define ADJUST_ZERO 13

# define EMPTY_STRING -1
# define FLAG "cspdiuxX%/"
# define FLAGTOKKEN "0123456789*-."

typedef	struct	s_tokken_int
{
	int		precision_dot;
	int		precision_zero;
}				t_tokken_int;

typedef struct	s_tokken_string
{
	int		empty_string;
	int		precision_zero_string;
}				t_tokken_string;

typedef struct	s_tokken
{
	int				adjustment;
	int				left;
	int				precision;
	int				precision_number;
	int				precision_zero;
	int				precision_zero_number;
	int				error;
	char			tokken;
	t_tokken_string	string_tokken;
}				t_tokken;

/*
**      ===================
**     |    ft_printf.c    |
**      ===================
*/

int				ft_printf(const char *string, ...);

/*
**-------------------------------------------------------------------
*/

/*
**      ===================
**     |    check_flag.c   |
**      ===================
*/

int				deal_with_arg(const char *string, va_list list_arg);
char			*ft_strjoin_pourcent(char *buffer);
char			*find_next_arg(char *string);
int				type_of_arg(const char *str);

/*
**-------------------------------------------------------------------
*/

/*
**      ======================
**     |    type_of_flag.c    |
**      ======================
*/

int				character_arg(const char *string, va_list list_arg, t_tokken *tokkens);
int				string_arg(const char *string, va_list list_arg, t_tokken *tokkens);
int				int_decimal_arg(const char *string, va_list list_arg, t_tokken *tokkens);
int				unsigned_int_decimal_arg(const char *string, va_list list_arg, t_tokken *tokkens);
int				unsigned_hexadecimal_arg(const char *string, va_list list_arg, t_tokken *tokkens);

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

int				pointer_arg(const char *string, va_list list_arg, t_tokken *tokkens);
int				pourcent_arg(const char *string, va_list list_arg, t_tokken *tokkens);

/*
**      ===============
**     |    utils.c    |
**      ===============
*/

char			*ft_itoa_unsigned(unsigned long int n);
char			*ft_itoa_base16(unsigned int n);
char			*ft_itoa_base16_long(unsigned long int n);

/*
**-------------------------------------------------------------------
*/

t_tokken		*fill_tokken_struct(t_tokken *tokkens, const char *string, int flags, va_list arg);
t_tokken		*init_tokken(t_tokken *tokkens);
void			print_tokken(t_tokken *tokkens);
char			*read_tokkens_struct(t_tokken *tokkens, char *value, va_list arg, int flag);
char			*tokkens_precision(int precision_number, char *value);
void			count_character_for_return (t_tokken *tokkens, char *value);
int				find_minus_sign(const char *string, int index, int *ret);
int				find_pourcent_sign(const char *string, int index);
char			*toupper_x(char *value_string);

#endif
