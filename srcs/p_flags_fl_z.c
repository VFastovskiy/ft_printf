/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags_fl_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:10:39 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 15:11:54 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_fl_z_add3(t_print *printf)
{
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	else
	{
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_fl_z_add2(t_print *printf, int y)
{
	if (printf->itoa[0] == '-')
	{
		ft_putchar_pf('-', printf);
		printf->itoa++;
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	else
	{
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_fl_z_add(t_print *printf, int y)
{
	if (printf->itoa[0] == '-')
	{
		printf->itoa++;
		ft_putchar_pf('-', printf);
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
	else
	{
		while (y++ < printf->width)
			ft_putchar_pf('0', printf);
		while (printf->precision-- > 0)
			ft_putchar_pf('0', printf);
		ft_putstr_pf(printf->itoa, printf);
	}
}

void	print_flag_float_zero(t_print *printf, int i, int y)
{
	int		f;

	f = 0;
	if ((int_zero_prec(printf, y, f)) == 0)
		return ;
	else if (printf->width > i + printf->precision)
	{
		printf->width -= i + printf->precision;
		if (printf->prec > 0)
			print_fl_z_add(printf, y);
		else
			print_fl_z_add2(printf, y);
	}
	else if (printf->width <= i + printf->precision)
		print_fl_z_add3(printf);
}
