/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:31:04 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 21:25:29 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define MIN_ZERO		0x8000000000000000

typedef	struct
{
	int					x;
	int					d;
	int					r;
}						t_round;

typedef	struct
{
	char				x;
	char				*str;
	char				*c;
	unsigned int		tmp;
	unsigned long int	tmp2;
	int					size;
	int					i;
}						t_ibb;

typedef	struct
{
	int					w;
	char				*str;
	int					i;
	int					skip;
	char				*tmp;
}						t_width;

typedef	struct
{
	int					i;
	char				*res;
	int					result;
	char				*tmp;
}						t_prec;

typedef	struct
{
	char				s;
	int					i;
	int					y;
}						t_flags;

typedef	struct
{
	char				x;
	char				*c;
	char				*str;
	unsigned long		tmp;
	int					size;
	int					i;
}						t_ibp;

typedef	struct
{
	char				x;
	char				*c;
	char				*str;
	char				*tmp;
	int					size;
	int					i;
}						t_ib;

typedef	struct
{
	int					a;
	int					x;
}						t_t;

typedef	struct
{
	int					f;
	int					i;
	int					y;
	char				*saveitoa;
}						t_ibf;

typedef	struct
{
	int					j;
	int					a;
	int					v;
	int					s;
}						t_fparse;

typedef	struct
{
	int					i;
	int					z;
	char				*str2;
	char				*tmp;
	char				*tmp2;
}						t_za;

typedef	struct
{
	int					i;
	int					d;
	int					fprec;
	int					a;
	int					k;
	int					z;
	int					b;
	int					q;
	long double			m;
	long double			afterdot;
	long double			integer;
	char				*ftoa_m[2];
	char				*ftoa_a[2];
	char				*tmp2;
	unsigned long		neg_zer;
	t_fparse			fp;
}						t_lfloat;

typedef	struct
{
	int					i;
	int					d;
	int					fprec;
	int					a;
	int					q;
	int					b;
	int					k;
	int					z;
	long double			afterdot;
	long double			integer;
	char				*ftoa_m[2];
	char				*ftoa_a[2];
	char				*tmp2;
	unsigned long		neg_zer;
	t_fparse			fp;
}						t_float;

typedef	struct
{
	int					length;
	int					width;
	int					precision;
	int					prec;
	int					number;
	int					fl;
	int					count;
	int					nan;
	int					uns;
	int					x;
	char				ch;
	unsigned int		number_u;
	unsigned long		p;
	char				*str;
	char				*pointer;
	char				*flags;
	char				*c;
	char				*itoa;
	char				*f;
}						t_print;

void					float_round_one(char *ftoa_a, int **i, t_round	*p);
void					float_round(char *ftoa_a, int *i, int fprec);
void					check_float_precision(t_print *printf, int *fprec);
int						fuk_float(double floatval, t_float *ld, \
														t_print *printf);
int						fuk_longfloat(long double floatval, t_lfloat *ld, \
														t_print *printf);
void					check_if_neg_ld(double floatval, t_lfloat *ld);
void					check_if_neg_d(double floatval, t_float *ld);
void					ft_catafterdot_long(t_lfloat *ld);
void					ft_catafterdot_d(t_float *ld);
void					long_math(long double i, int k, char **str);
void					parse_float_d(t_float *ld, double fv);
void					parse_float_ld(t_lfloat *ld, long double fv);
void					zero_appending(t_float *d);
void					zero_appending_l(t_lfloat *d);
void					float_init_ld(long double floatval, t_lfloat *ld);
void					float_init(double *z, double floatval, t_float *ld);
char					ft_choose_letter(int n, int flag);
void					ft_putchar_pf(int c, t_print *printf);
void					ft_putstr_pf(const char *str, t_print *printf);
char					*ft_pointer_itoa(unsigned long n);
char					*ft_itoa_base(unsigned int n, int base, int flag);
char					*ft_ftoa_single(double n, t_print *printf);
char					*ft_ftoa_long(long double floatval, t_print *printf);
char					*ft_itoa_long(long nb);
char					*ft_itoa_double(double nb);
int						ft_read_flag_int(char *flag);
char					*ft_append(char *str, char c);
char					*ft_revappend(char c, char *str);
char					*ft_uitoa(unsigned int nb);
int						ft_int_len_d(double nb);
int						ft_int_len(long long nb);
void					check_precision(t_print *printf, int i);
void					print_flags_minushash(t_print *printf, int i, \
														int y, char c);
void					print_flag_zerohash_x(t_print *printf, int i, \
														int y, char c);
void					print_flag_zerohash_o(t_print *printf, int i, int y);
void					print_flag_plus(t_print *printf, int i, int y);
void					print_flag_space(t_print *printf, int i, int y);
void					print_flag_minplu(t_print *printf, int i, int y);
void					print_flag_minspace(t_print *printf, int i, int y);
void					print_flag_minus(t_print *printf, int i, int y);
void					print_flag_hash_x(t_print *printf, int i, int y, \
														char c);
void					print_flag_hash_o(t_print *printf, int i, int y, \
														char c);
void					print_flags_minushash_x(t_print *printf, int i, \
														int y, char c);
void					print_flags_minushash_o(t_print *printf, int i, \
														int y, char c);
int						int_zero_prec(t_print *printf, int y, int f);
int						int_zero_prec_o(t_print *printf);
void					print_flag_zero(t_print *printf, int i, int y);
void					print_flag_no(t_print *printf, int i, int y);
void					print_char_minus(t_print *printf, int i, int y);
void					print_char_noflag(t_print *printf, int i, int y);
void					print_char_mizer(t_print *printf, int i, int y);
void					print_char_zero(t_print *printf, int i, int y);
void					print_point_minus(t_print *printf, int i, int y);
void					print_point_noflag(t_print *printf, int i, int y);
void					print_str_minus(t_print *printf, int i, int y);
void					print_str_no(t_print *printf, int i, int y);
void					print_float(t_print *printf);
int						ft_read_flag(char *flag, t_print *printf);
void					print_flag_float_no(t_print *printf, int i, int y);
void					s_print_float(t_print *printf, va_list **ap);
void					print_hex_oct(t_print *printf, va_list **ap, char c);
void					ft_print_hexoctal(t_print *printf, char c);
void					ft_print_unsigned_number(t_print *printf);
void					ft_print_signed_number(t_print *printf);
void					print_dec(t_print *printf, va_list **ap, char c);
void					print_udec(t_print *printf, va_list **ap, char c);
void					s_print_csp(t_print *printf, va_list **ap, char c);
void					ft_print_char(t_print *printf);
void					ft_print_pointer(t_print *printf);
void					ft_print_str(t_print *printf);
void					ft_print_perc(t_print *printf);
void					ft_print_float(t_print *printf);
void					analyze_spec(t_print *printf, va_list *ap, char **c);
void					analyze_sum(t_print *printf, va_list *ap, char **c);
int						analyze_precision(char **str, va_list *ap);
int						analyze_width(char **width, va_list *ap);
char					*analyze_flags(char **flags);
int						analyze_length(char **str);
int						int_zero_prec(t_print *printf, int y, int f);
void					zero_appending_l(t_lfloat *ld);
void					zero_appending(t_float *d);
long double				ft_pow(double n, int pow);
void					check_float_precision(t_print *printf, int *fprec);
void					print_flag_zero_plus(t_print *printf, int i, int y);
void					print_flag_space_zero(t_print *printf, int i, int y);
unsigned int			ft_int_len_ui(unsigned int nb);
unsigned int			ft_int_len_uli(unsigned long int nb);
unsigned int			ft_int_len_ulli(unsigned long long int nb);
char					*ft_uitoa_ull(unsigned long long int nb);
char					*ft_uitoa(unsigned int nb);
char					*ft_uitoa_ul(unsigned long int nb);
char					*ft_itoa_lli(long long int nb);
char					*ft_itoa_li(long int nb);
char					*ft_itoa_base_ull(unsigned long long int n, int base, \
															int flag);
char					*ft_itoa_base_ul(unsigned long int n, int base, \
															int flag);
void					print_flag_float_hash(t_print *printf, int i, int y);
void					print_flag_float_zero(t_print *printf, int i, int y);
void					print_flag_float_zero_plus(t_print *printf, int i, \
															int y);
void					print_flag_fl_hash_minus(t_print *printf, int i, int y);
void					print_flag_fl_zero_plus(t_print *printf, int i, int y);
void					print_flag_plusminushash(t_print *printf, int i, int y);
void					print_flag_fl_zerospace(t_print *printf, int i, int y);
void					print_flag_minspacehash(t_print *printf, int i, int y);
char					*ft_itoa_ulonglong(unsigned long long nb);
int						ft_int_len_ull(unsigned long long int nb);
int						ft_int_len_ld(long double nb);
int						ft_printf(const char *format, ...);
char					*ft_itoa_long_double(long double nb);
void					long_math(long double i, int k, char **str);
void					long_math_l(long double i, int k, char **str);
void					float_round(char *ftoa_a, int *i, int fprec);
void					ft_print_inf(t_print *printf);
void					ft_print_nan(t_print *printf);
void					fibp(t_print *printf, int a, t_ibf *i);
int						analyze_length_add(char **str);
void					ft_init(char **width, t_width *wt);
int						ft_negative(int nb);
int						ft_sign(int nb);

#endif
