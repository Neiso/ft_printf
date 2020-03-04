/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:50:07 by douatla           #+#    #+#             */
/*   Updated: 2020/03/04 15:03:57 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../../includes/libft.h"
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
# define AD_ZER 13

# define EMPTY_STRING -1
# define FLAG "cspdiuxX%/"
# define FLAGTOKKEN "0123456789*-."

typedef struct	s_flag_s
{
	int		empty_string;
	int		precision_zero_string;
}				t_flag_s;

typedef struct	s_flag
{
	int				adjust;
	int				left;
	int				preci;
	int				preci_val;
	int				preci_zero;
	int				preci_zero_val;
	char			tokken;
	t_flag_s		string_tokken;
}				t_flag;

/*
**      ===================
**     |    ft_printf.c    |
**      ===================
*/

int				ft_printf_tokken(const char *string,
					int *ret, int pos, int tmp);
int				ft_printf(const char *string, ...);

/*
**      ===================
**     |    check_flag.c   |
**      ===================
*/

int				deal_with_arg(const char *string, va_list list_arg);
int				type_of_arg(const char *str);

/*
**      ===================
**     |    find_tokken.c  |
**      ===================
*/

t_flag			*init_tokken(t_flag *flags);
int				asterix(t_flag *flags, va_list arg, int flag);
int				read_value(int pos, const char *str, int tokken, t_flag *flags);
int				pre_fill(t_flag *flags, const char *string, va_list arg);
t_flag			*fill_struct(t_flag *flags, char *str, int flag, va_list arg);

/*
**      ===================
**     |    deal_tokken.c  |
**      ===================
*/

char			*flags_adjustement(int adjustement, char *value, int left);
char			*flag_int_preci(char *val, int preci_val,
					int preci, t_flag *flags);
char			*flag_preci_string(int preci_val, char *value, t_flag *flags);
char			*tokken_preci_pointer(char *value, int preci_val);
char			*read_flags_struct(t_flag *flags, char *value, int flag);

/*
**      ======================
**     |    type_of_flag.c    |
**      ======================
*/

int				character_arg_null(char value[2], t_flag *flags);
int				character_arg(const char *string,
					va_list list_arg, t_flag *flags);
int				string_arg(const char *string, va_list list_arg, t_flag *flags);
int				int_decimal_arg(const char *string,
					va_list list_arg, t_flag *flags);
int				unsigned_int_arg(const char *string,
					va_list list_arg, t_flag *flags);

/*
**      =======================
**     |    type_of_flag2.c    |
**      =======================
*/

int				unsigned_hexa_arg(const char *string,
					va_list list_arg, t_flag *flags);
int				pointer_arg(const char *string,
					va_list list_arg, t_flag *flags);
int				pourcent_arg(const char *string,
					va_list list_arg, t_flag *flags);

/*
**      ====================
**     |	func_utils.c    |
**      ====================
*/

char			*ft_itoa_unsigned(unsigned long int n);
char			*ft_itoa_base16(unsigned int n);
char			*ft_itoa_base16_long(unsigned long int n);
void			count_character_for_return(t_flag *flags, char *value);
char			*toupper_x(char *value_string);

/*
**      =====================
**     |	func_utils_2.c   |
**      =====================
*/

void			flags_adjustment_left(char *value, char *value_cpy, int adjust);
char			*flags_int_preci_neg(char *value, int bool, t_flag *flags);
int				aste2(int i, char *string, va_list arg, t_flag *flags);

#endif
