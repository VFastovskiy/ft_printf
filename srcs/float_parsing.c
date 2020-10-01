/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:25:15 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 16:00:34 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_float_ld(t_lfloat *ld, long double fv)
{
	long double		b;
	long double		c;
	int				i[ld->k];

	ld->fp.j = 0;
	c = fv;
	ld->ftoa_m[0] = (char*)ft_memalloc(sizeof(char) * ld->k + 1);
	ld->fp.v = -1;
	ld->fp.s = ld->k;
	while (ld->fp.j <= ld->fp.s && ld->k >= 1)
	{
		ld->k > 1 ? (ld->fp.a = c / ft_pow(10, ld->k - 1)) : 1;
		ld->k == 1 ? ld->fp.a = c : 1;
		i[ld->fp.j] = ld->fp.a;
		ld->fp.j++;
		ld->k > 1 ? (b = ld->fp.a * ft_pow(10, ld->k - 1)) : 1;
		c = c - b;
		ld->k--;
	}
	while (ld->fp.v++ < ld->fp.s)
		ld->ftoa_m[0][ld->fp.v] = i[ld->fp.v] + 48;
	ld->ftoa_m[0][ld->fp.s] = '\0';
}

void	parse_float_d(t_float *ld, double fv)
{
	double		b;
	double		c;
	int			i[ld->k];

	ld->fp.j = 0;
	c = fv;
	ld->ftoa_m[0] = (char*)ft_memalloc(sizeof(char) * ld->k + 1);
	ld->fp.v = -1;
	ld->fp.s = ld->k;
	while (ld->fp.j <= ld->fp.s && ld->k >= 1)
	{
		ld->k > 1 ? (ld->fp.a = c / ft_pow(10, ld->k - 1)) : 1;
		ld->k == 1 ? ld->fp.a = c : 1;
		i[ld->fp.j] = ld->fp.a;
		ld->fp.j++;
		ld->k > 1 ? (b = ld->fp.a * ft_pow(10, ld->k - 1)) : 1;
		c = c - b;
		ld->k--;
	}
	while (ld->fp.v++ < ld->fp.s)
		ld->ftoa_m[0][ld->fp.v] = i[ld->fp.v] + 48;
	ld->ftoa_m[0][ld->fp.s] = '\0';
}

void	long_math(long double i, int k, char **str)
{
	char *tmp;

	i /= ft_pow(10, k);
	i *= ft_pow(10, 16);
	str[0] = ft_itoa_long_double(i);
	tmp = str[0];
	i = i - (unsigned long long)i;
	if (k > 16)
		i *= ft_pow(10, k - 16);
	str[1] = ft_itoa_long_double(i);
	str[0] = ft_strjoin(str[0], str[1]);
	ft_strdel(&tmp);
	ft_strdel(&str[1]);
}

void	ft_catafterdot_long(t_lfloat *ld)
{
	if (ld->afterdot != 0)
		ld->afterdot = ld->afterdot * ft_pow(10, ld->fprec + 1);
	if ((ld->k = ft_int_len_ld(ld->afterdot)) > 16)
		long_math(ld->afterdot, ld->k, ld->ftoa_a);
	else
		ld->ftoa_a[0] = ft_itoa_long_double(ld->afterdot);
	ld->d = ft_strlen(ld->ftoa_a[0]);
	ld->ftoa_a[0][ld->d] = '\0';
}

void	ft_catafterdot_d(t_float *ld)
{
	if (ld->afterdot != 0)
		ld->afterdot = ld->afterdot * ft_pow(10, ld->fprec + 1);
	if ((ld->k = ft_int_len_ld(ld->afterdot)) > 16)
		long_math(ld->afterdot, ld->k, ld->ftoa_a);
	else
		ld->ftoa_a[0] = ft_itoa_long_double(ld->afterdot);
	ld->d = ft_strlen(ld->ftoa_a[0]);
	ld->ftoa_a[0][ld->d] = '\0';
}
