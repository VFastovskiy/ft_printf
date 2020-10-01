/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_analyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:21:27 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/04 18:34:49 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_float_precision(t_print *printf, int *fprec)
{
	printf->prec = printf->precision;
	if (printf->prec < 0)
		*fprec = 6;
	else if (printf->prec > 0)
		*fprec = printf->prec;
	else if (printf->prec == 0)
		*fprec = 0;
}

int		fuk_float(double floatval, t_float *ld, t_print *printf)
{
	printf->nan = 0;
	if (floatval != floatval)
	{
		ld->ftoa_m[0] = ft_strdup("nan");
		printf->nan = 1;
		return (1);
	}
	else if (floatval == 1 / -0.0)
	{
		ld->ftoa_m[0] = ft_strdup("-inf");
		printf->nan = 1;
		return (1);
	}
	else if (floatval == 1 / 0.0)
	{
		ld->ftoa_m[0] = ft_strdup("inf");
		printf->nan = 1;
		return (1);
	}
	return (0);
}

int		fuk_longfloat(long double floatval, t_lfloat *ld, t_print *printf)
{
	printf->nan = 0;
	if (floatval != floatval)
	{
		ld->ftoa_m[0] = ft_strdup("nan");
		printf->nan = 1;
		return (1);
	}
	else if (floatval == 1 / -0.0)
	{
		ld->ftoa_m[0] = ft_strdup("-inf");
		printf->nan = 1;
		return (1);
	}
	else if (floatval == 1 / 0.0)
	{
		ld->ftoa_m[0] = ft_strdup("inf");
		printf->nan = 1;
		return (1);
	}
	return (0);
}

void	check_if_neg_ld(double floatval, t_lfloat *ld)
{
	double	x;
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	str = "-";
	tmp = ld->ftoa_m[0];
	x = (double)floatval;
	if ((floatval < 0) || ((ld->neg_zer = (*((long *)&x))) == MIN_ZERO))
	{
		ld->ftoa_m[0] = ft_strjoin(str, ld->ftoa_m[0]);
		i++;
	}
	i > 0 ? ft_strdel(&tmp) : 1;
}

void	check_if_neg_d(double floatval, t_float *ld)
{
	char	*tmp;
	int		i;
	char	*str;

	i = 0;
	str = "-";
	tmp = ld->ftoa_m[0];
	if ((floatval < 0) || ((ld->neg_zer = (*((long *)&floatval))) == MIN_ZERO))
	{
		i++;
		ld->ftoa_m[0] = ft_strjoin(str, ld->ftoa_m[0]);
	}
	i > 0 ? ft_strdel(&tmp) : 1;
}
