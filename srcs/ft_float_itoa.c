/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:46:53 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 15:53:36 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	float_appending(t_float *ld)
{
	char *tmp66;

	tmp66 = ld->ftoa_m[0];
	ld->ftoa_a[0][ld->fprec] = '\0';
	ld->ftoa_m[0] = ft_append(ld->ftoa_m[0], '.');
	ld->tmp2 = ld->ftoa_m[0];
	ld->ftoa_m[0] = ft_strjoin(ld->ftoa_m[0], ld->ftoa_a[0]);
	ft_strdel(&tmp66);
	ft_strdel(&ld->tmp2);
	ft_strdel(&ld->ftoa_a[0]);
}

void	ftoa_ftoa_lala(t_float *ld, int i, double fv)
{
	if (ld->q == 0)
	{
		i == 1 ? ld->integer += 1 : 1;
		(i == 3 && (int)ld->integer % 2 != 0) ? ld->integer += 1 : 1;
		ld->ftoa_m[0] = ft_itoa_long_double(ld->integer);
	}
	check_if_neg_d(fv, ld);
}

char	*ft_ftoa_single(double floatval, t_print *printf)
{
	t_float	ld;
	int		i;
	double	z;

	ld.d = 0;
	ld.q = 0;
	i = 0;
	ld.ftoa_m[0] = NULL;
	if (fuk_float(floatval, &ld, printf))
		return (ld.ftoa_m[0]);
	float_init(&z, floatval, &ld);
	check_float_precision(printf, &ld.fprec);
	ft_catafterdot_d(&ld);
	ld.d = ft_strlen(ld.ftoa_a[0]);
	ld.ftoa_a[0][ld.d] = '\0';
	zero_appending(&ld);
	float_round(ld.ftoa_a[0], &i, ld.fprec);
	ftoa_ftoa_lala(&ld, i, floatval);
	if (printf->precision == 0)
	{
		ft_strdel(&ld.ftoa_a[0]);
		return (ld.ftoa_m[0]);
	}
	float_appending(&ld);
	return (ld.ftoa_m[0]);
}
