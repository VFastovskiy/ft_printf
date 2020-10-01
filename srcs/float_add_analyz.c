/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_add_analyz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:18:16 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 17:47:25 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero_appending(t_float *d)
{
	t_za	za;

	za.i = 0;
	za.z = 0;
	d->a = d->d - 1;
	za.tmp = d->ftoa_a[0];
	za.z = d->fprec - d->a;
	if (za.z > 0)
	{
		za.str2 = ft_memalloc(za.z + 1);
		za.tmp2 = za.str2;
		za.str2 = ft_memset(za.str2, '0', za.z);
		za.str2[za.z] = '\0';
		d->ftoa_a[0] = ft_strjoin(za.str2, za.tmp);
		ft_strdel(&za.tmp);
		ft_strdel(&za.tmp2);
	}
	d->d = ft_strlen(d->ftoa_a[0]);
}

void	zero_appending_l(t_lfloat *d)
{
	t_za	za_l;

	za_l.i = 0;
	za_l.z = 0;
	d->a = d->d - 1;
	za_l.tmp = d->ftoa_a[0];
	za_l.z = d->fprec - d->a;
	if (za_l.z > 0)
	{
		za_l.str2 = ft_memalloc(za_l.z + 1);
		za_l.tmp2 = za_l.str2;
		za_l.str2 = ft_memset(za_l.str2, '0', za_l.z);
		za_l.str2[za_l.z] = '\0';
		d->ftoa_a[0] = ft_strjoin(za_l.str2, za_l.tmp);
		ft_strdel(&za_l.tmp);
		ft_strdel(&za_l.tmp2);
	}
	d->d = ft_strlen(d->ftoa_a[0]);
}

void	float_init_ld(long double floatval, t_lfloat *ld)
{
	ld->afterdot = 0;
	ld->m = ((floatval < 0) ? (floatval * -1) : (floatval * 1));
	if ((ld->k = ft_int_len_ld(ld->m)) > 19)
	{
		parse_float_ld(ld, ld->m);
		ld->afterdot = 0;
		ld->q = 32;
	}
	else
	{
		ld->integer = (unsigned long long)ld->m;
		if (ld->m > ld->integer)
			ld->afterdot = ld->m - ld->integer;
	}
}

void	float_init(double *z, double floatval, t_float *ld)
{
	ld->afterdot = 0;
	*z = ((floatval < 0) ? (floatval * -1) : (floatval * 1));
	if ((ld->k = ft_int_len_ld(*z)) > 16)
	{
		parse_float_d(ld, *z);
		ld->afterdot = 0;
		ld->q = 32;
	}
	else
	{
		ld->integer = (unsigned long long)*z;
		if (*z > ld->integer)
			ld->afterdot = *z - ld->integer;
	}
}
