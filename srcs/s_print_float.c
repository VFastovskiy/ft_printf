/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:10:14 by blakeish          #+#    #+#             */
/*   Updated: 2020/08/04 18:51:07 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		fibp(t_print *printf, int a, t_ibf *i)
{
	i->saveitoa = printf->itoa;
	i->f = ft_read_flag(printf->flags, printf);
	i->i = ft_strlen(printf->itoa);
	i->y = 0;
	a == 1 ? printf->precision = 0 : check_precision(printf, i->i);
}

void		ft_print_float_add(t_print *printf, t_ibf *i)
{
	if (i->f == 20)
		print_flag_float_hash(printf, i->i, i->y);
	if (i->f == 27)
		print_flag_fl_hash_minus(printf, i->i, i->y);
	if (i->f == 67 || i->f == 72)
		print_flag_plusminushash(printf, i->i, i->y);
	if (i->f == 6)
		print_flag_fl_zerospace(printf, i->i, i->y);
	if (i->f == 28 || i->f == 33)
		print_flag_minspacehash(printf, i->i, i->y);
	else if (i->f == 0)
		print_flag_no(printf, i->i, i->y);
}

void		ft_print_float(t_print *printf)
{
	t_ibf	i;

	fibp(printf, 0, &i);
	if (i.f == 7 || i.f == 12)
		print_flag_minus(printf, i.i, i.y);
	if (i.f == 40 || i.f == 41)
		print_flag_plus(printf, i.i, i.y);
	if (i.f == 1)
		print_flag_space(printf, i.i, i.y);
	if (i.f == 5)
		print_flag_float_zero(printf, i.i, i.y);
	if (i.f == 47 || i.f == 52)
		print_flag_minplu(printf, i.i, i.y);
	if (i.f == 8 || i.f == 13)
		print_flag_minspace(printf, i.i, i.y);
	if (i.f == 45)
		print_flag_float_zero_plus(printf, i.i, i.y);
	ft_print_float_add(printf, &i);
	ft_strdel(&i.saveitoa);
}

void		s_print_float(t_print *printf, va_list **ap)
{
	printf->fl = 1;
	if (printf->length == 5)
		printf->itoa = ft_ftoa_long(va_arg(**ap, long double), printf);
	else
		printf->itoa = ft_ftoa_single(va_arg(**ap, double), printf);
	if (printf->nan == 1 && (ft_strcmp(printf->itoa, "nan") == 0))
		ft_print_nan(printf);
	else if (printf->nan == 1 && ft_strcmp(printf->itoa, "nan") != 0)
		ft_print_inf(printf);
	else
		ft_print_float(printf);
}
