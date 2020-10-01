/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longfloat_ftoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:31:43 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 17:48:19 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	long_float_appending(t_lfloat *ld)
{
	char *tmp66;

	ld->ftoa_a[0][ld->fprec] = '\0';
	tmp66 = ld->ftoa_m[0];
	ld->ftoa_m[0] = ft_append(ld->ftoa_m[0], '.');
	ld->tmp2 = ld->ftoa_m[0];
	ld->ftoa_m[0] = ft_strjoin(ld->ftoa_m[0], ld->ftoa_a[0]);
	ft_strdel(&tmp66);
	ft_strdel(&ld->tmp2);
	ft_strdel(&ld->ftoa_a[0]);
}

void	long_ftoa_lalala(t_lfloat *ld, long double fv, int i)
{
	if (ld->q == 0)
	{
		i == 1 ? ld->integer += 1 : 0;
		(i == 3 && (int)ld->integer % 2 != 0) ? ld->integer += 1 : 1;
		ld->ftoa_m[0] = ft_itoa_long_double(ld->integer);
	}
	check_if_neg_ld(fv, ld);
}

char	*ft_ftoa_long(long double floatval, t_print *printf)
{
	t_lfloat	ld;
	int			i;

	ld.d = 0;
	ld.q = 0;
	i = 0;
	ld.ftoa_m[0] = NULL;
	if (fuk_longfloat(floatval, &ld, printf))
		return (ld.ftoa_m[0]);
	float_init_ld(floatval, &ld);
	check_float_precision(printf, &ld.fprec);
	ft_catafterdot_long(&ld);
	zero_appending_l(&ld);
	float_round(ld.ftoa_a[0], &i, ld.fprec);
	long_ftoa_lalala(&ld, floatval, i);
	if (printf->precision == 0)
	{
		ft_strdel(&ld.ftoa_a[0]);
		return (ld.ftoa_m[0]);
	}
	long_float_appending(&ld);
	return (ld.ftoa_m[0]);
}
